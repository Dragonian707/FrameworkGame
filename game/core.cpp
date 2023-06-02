#include <fstream>
#include <sstream>

#include "core.h"



Core::Core()
{
	deltaTime = 0;
	lastTime = GetTime();
}

Core::~Core()
{
	
}

void Core::Run(Scene* scene)
{
	//set the deltatime
	SetDeltatime();

	//update the scene and the objects in it
	scene->UpdateObject(deltaTime);
}

void Core::SetDeltatime()
{
	double newTime = GetTime();
	deltaTime = newTime - lastTime;
	lastTime = newTime;
}