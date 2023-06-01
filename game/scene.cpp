#include <fstream>
#include <sstream>

#include "scene.h"



Scene::Scene()
{
	
}

Scene::~Scene()
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		delete objects[i];
		objects[i] = nullptr;
	}
}

void Scene::UpdateScene(float deltatime)
{
	this->update(deltatime);

	for (Object* obj : objects)
	{
		obj->update(deltatime);
	}
}

void Scene::AddObject(Object* object)
{
	objects.push_back(object);
}