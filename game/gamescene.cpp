#include <fstream>
#include <sstream>

#include "gamescene.h"



GameScene::GameScene()
{
	activescene = 1;

	testTrack = ResourceManager::Instance()->GetMusic("assets/music_evade.ogg");

	srand(time(NULL));

	spawner = new Spawner();
	player = new Player();

	failtext = new TextSprite();
	failtext->SetMessage("       you died!\nPress ENTER to reset");


	AddObject(player);
	AddObject(failtext);

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
		ResumeMusicStream(testTrack);
		DeleteObject(goToMouse);
	}

	UpdateMusicStream(testTrack);
	timer += deltaTime;
	
	if (timer >= 0.5f)
	{
		timer = 0;
		std::vector<Spike*> sp;

		bool pattern = false;
		if (rand() % 3 == 0)
		{
			pattern = true;
		}
		sp = spawner->Spawn(pattern);

		for (Spike* s : sp)
		{
			spikes.push_back(s);
			AddObject(s);
		}
	}

	for (int i = spikes.size() - 1; i >= 0; i--) 
	{
		if (CheckCollisionCircles(spikes[i]->position, spikes[i]->getTuxture().width / 2, player->position, player->getTuxture().width * player->scale / 2) && !player->dead)
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
		PauseMusicStream(testTrack);
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

	StopMusicStream(testTrack);
	for (int i = spikes.size() - 1; i >= 0; i--)
	{
		DeleteObject(spikes[i]);
		spikes[i] = nullptr;
		spikes.erase(spikes.begin() + i);
	}
	failtext->position = Vector2(-200, -200);
	player->dead = false;
	player->color = GREEN;
	PlayMusicStream(testTrack);
	HideCursor();

	paused = false;
	for (Spike* s : spikes)
	{
		s->paused = false;
	}
	player->paused = false;
}