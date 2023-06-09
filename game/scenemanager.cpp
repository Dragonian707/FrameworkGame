#include <fstream>
#include <sstream>

#include "scenemanager.h"


SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager()
{
	SetActiveScene();
}

SceneManager::~SceneManager()
{
	if (currentScene != nullptr)
	{
		delete currentScene;
		currentScene = nullptr;
	}
}

SceneManager* SceneManager::Instance()
{
	if (SceneManager::_instance == nullptr)
	{
		_instance = new SceneManager();
	}
	return _instance;
}

Scene* SceneManager::GetActiveScene()
{
	SetActiveScene();
	return currentScene;
}

void SceneManager::SetActiveScene()
{
	if (currentScene == nullptr)
	{
		currentScene = new StartScene();
	}

	if (currentScene->activescene == active)
	{
		return;
	}

	switch (currentScene->activescene)
	{
		case 0:
			delete currentScene;
			currentScene = new StartScene();
			active = startscene;
			break;
		case 1:
			delete currentScene;
			currentScene = new GameScene();
			active = gamescene;
			break;
		case 2:
			delete currentScene;
			currentScene = new OptionScene(active);
			active = optionscene;
			break;
		default:
			active = startscene;
			delete currentScene;
			currentScene = new StartScene();
			break;
	}
}
