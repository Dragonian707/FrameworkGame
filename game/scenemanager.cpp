#include <fstream>
#include <sstream>

#include "testscene.h"



TestScene::TestScene()
{
	testTrack = ResourceManager::Instance()->GetMusic("assets/music_evade.ogg");

	srand(time(NULL));

	spawner = new Spawner();
	player = new Player();

	failtext = new TextSprite();
	failtext->SetMessage("       you died!\nPress ENTER to reset");

	AddObject(player);
	AddObject(failtext);

	HideCursor();

	ResetScene();
}

TestScene::~TestScene()
{

}

void TestScene::update(float deltaTime)
{
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

void TestScene::ResetScene()
{
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
}