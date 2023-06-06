#include <fstream>
#include <sstream>

#include "scene.h"



Scene::Scene()
{
	
}

Scene::~Scene()
{
	for (size_t i = 0; i < sprites.size(); i++)
	{
		delete sprites[i];
		sprites[i] = nullptr;
	}
}

void Scene::UpdateObject(float deltatime)
{
	this->update(deltatime);

	for (Sprite* spr : sprites)
	{
		spr->UpdateObject(deltatime);
	}
}

void Scene::AddObject(Sprite* sprite)
{
	sprites.push_back(sprite);
}