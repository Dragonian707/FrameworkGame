#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "raylib.h"

#include "scene.h"
#include "startscene.h"
#include "gamescene.h"
#include "optionscene.h"

class SceneManager
{
public:
	static SceneManager* Instance(); //singleton

	Scene* GetActiveScene();

	void SetActiveScene();

private:
	static SceneManager* _instance;
	/// @brief Constructor
	SceneManager();
	/// @brief Destructor
	virtual ~SceneManager();

	Scene* currentScene = nullptr;

	enum Active {startscene, gamescene, optionscene};
	Active active;
};

#endif
