#include <fstream>
#include <sstream>

#include "testscene.h"
#include "textsprite.h"



TestScene::TestScene()
{
	testTrack = ResourceManager::Instance()->GetMusic("assets/drummin.ogg");
	//PlayMusicStream(testTrack);

	srand(time(NULL));

	spawner = new Spawner();
	player = new Player();

	AddObject(player);

	HideCursor();
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
		if (rand() % 4 == 0)
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
		if (spikes[i]->dead)
		{
			DeleteObject(spikes[i]);
			spikes[i] = nullptr;
			spikes.erase(spikes.begin() + i);
		}
	}
}