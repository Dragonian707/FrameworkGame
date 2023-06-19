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
	ClearBackground(BLACK);

	//set the deltatime
	SetDeltatime();

	//update the scene and the objects in it
	scene->UpdateObject(deltaTime);

	EndDrawing();
}

void Core::SetDeltatime()
{
	double newTime = GetTime();
	deltaTime = newTime - lastTime;
	lastTime = newTime;
}