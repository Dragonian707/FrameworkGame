#include <fstream>
#include <sstream>

#include "core.h"



Core::Core()
{
	deltaTime = 0;
	lastTime = GetTime();
	InitAudioDevice();
}

Core::~Core()
{
	
}

void Core::Run(Scene* scene)
{
	BeginDrawing();
	ClearBackground(BACKGROUND);

	//set the deltatime
	SetDeltatime();

	//update the scene and the objects in it
	scene->UpdateObject(deltaTime);

	EndDrawing();
	if (scene->state == Scene::State::closegame) { running = false; };
}

void Core::SetDeltatime()
{
	double newTime = GetTime();
	deltaTime = newTime - lastTime;
	lastTime = newTime;
}