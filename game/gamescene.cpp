#include <fstream>
#include <sstream>

#include "gamescene.h"



GameScene::GameScene()
{
	//getting options from options.txt
	std::ifstream option("options.txt");
	std::vector<std::string> s;
	std::string temp;
	while (std::getline(option, temp, ':'))
	{
		s.push_back(temp);
		std::cout << temp << std::endl; // every three give a new value
	}

	if (s.size() >= 9)
	{
		float sp = std::stoi(s[4]);
		if (sp > 1000) { sp = 1000; };
		spawndelay = sp / 1000;

		sp = std::stoi(s[7]);
		if (sp > 100) { sp = 100; };
		patternchance = sp;
	}
	else
	{
		spawndelay = 0.5f;
		patternchance = 20;
	}
	//end of option getting & setting

	activescene = 1;

	gametrack = ResourceManager::Instance()->GetMusic("assets/music_evade.ogg");
	pausetrack = ResourceManager::Instance()->GetMusic("assets/menu_music.ogg");

	srand(time(NULL));

	spawner = new Spawner();
	player = new Player();

	failtext = new TextSprite();
	failtext->SetMessage("       you died!\nPress ENTER to reset");

	scoretext = new TextSprite();
	scoretext->CenterText(false);
	scoretext->position = Vector2(25, 25);

	AddObject(player);
	AddObject(failtext);
	AddObject(scoretext);

	ResetScene();
}

GameScene::~GameScene()
{
	for (Spike* s : spikes)
	{
		DeleteObject(s);
	}

	DeleteObject(failtext);
	DeleteObject(player);
	DeleteObject(scoretext);

	if (goToMouse != nullptr)
	{
		DeleteObject(goToMouse);
	}

	delete spawner;
	spawner = nullptr;

	if (pauseHud != nullptr)
	{
		DeleteObject(pauseHud);
	}
}

void GameScene::update(float deltaTime)
{
	if (IsKeyPressed(KEY_BACKSPACE)) //maybe choose different key?   Can't use escape sadly, too much input delay
	{
		PauseGame();
	}

	if (paused)
	{
		UpdateMusicStream(pausetrack);
		if (pauseHud != nullptr)
		{
			switch (pauseHud->state)
			{
			case 0:
				break;
			case 1:
				PauseGame();
				break;
			case 2:
				player->ready = true;
				ResetScene();
				return;
				break;
			case 3:
				OpenOptions();
				break;
			case 4:
				CloseGame();
				break;
			}
		}

		if (!player->CheckReady())
		{
			return;
		}

		paused = false;
		for (Spike* s : spikes)
		{
			s->paused = false;
		}
		player->paused = false;
		ResumeMusicStream(gametrack);
		PauseMusicStream(pausetrack);
		DeleteObject(goToMouse);
		HideCursor();
	}
//--------------------------end of pause checks------------------------------------------------

	UpdateMusicStream(gametrack);
	timer += deltaTime;

	if (!player->dead)
	{
		score += deltaTime * 100;
		std::string message = "";
		message += "Score: ";
		message += std::to_string((int)score);
		scoretext->SetMessage(message);
	}
	
	if (timer >= spawndelay)
	{
		timer = 0;
		std::vector<Spike*> sp;

		bool patterned = false;
		if (patternchance >= rand() % 100)
		{
			patterned = true;
		}
		sp = spawner->Spawn(patterned);

		for (Spike* s : sp)
		{
			spikes.push_back(s);
			AddObject(s);
		}
	}

	for (int i = spikes.size() - 1; i >= 0; i--) 
	{
		if (CheckCollisionCircles(spikes[i]->position, spikes[i]->getTexture().width / 2, player->position, player->getTexture().width * player->scale / 2) && !player->dead)
		{
			std::cout << "YOU DIED BITCH!!!\n";
			failtext->position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2);
			player->dead = true;
		}

		if (spikes[i]->dead)
		{
			DeleteObject(spikes[i]);
			spikes[i] = nullptr;
			spikes.erase(spikes.begin() + i);
		}
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		ResetScene();
	}

}

void GameScene::PauseGame()
{
	if (!paused)
	{
		paused = true;
		for (Spike* s : spikes)
		{
			s->paused = true;
		}
		player->paused = true;
		PauseMusicStream(gametrack);
		PlayMusicStream(pausetrack);
		EnableCursor();

		pauseHud = new PauseHud();
		AddObject(pauseHud);
	}
	else
	{
		player->paused = false;
		goToMouse = new TextSprite();
		goToMouse->SetMessage("move back to the cursor");
		goToMouse->position = Vector2(SCRWIDTH / 2, 50);
		AddObject(goToMouse);
		pauseHud->state = PauseHud::State::nothing;
		DeleteObject(pauseHud);
	}
}

void GameScene::ResetScene()
{
	if (pauseHud != nullptr)
	{
		DeleteObject(pauseHud);
	}

	StopMusicStream(gametrack);
	for (int i = spikes.size() - 1; i >= 0; i--)
	{
		DeleteObject(spikes[i]);
		spikes[i] = nullptr;
		spikes.erase(spikes.begin() + i);
	}
	failtext->position = Vector2(-200, -200);
	player->dead = false;
	player->color = spawner->GetPlayerColor();
	PlayMusicStream(gametrack);
	HideCursor();
	score = 0;

	paused = false;
	for (Spike* s : spikes)
	{
		s->paused = false;
	}
	player->paused = false;
}

void GameScene::OpenOptions()
{
	activescene = 2;
}