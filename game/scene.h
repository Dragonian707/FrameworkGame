#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"
#include "object.h"
#include <vector>

class Scene
{
public:
	/// @brief Constructor
	Scene();
	/// @brief Destructor
	virtual ~Scene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime) = 0;

	void AddObject(Object* object);

	void UpdateScene(float deltatime);

private:
	std::vector<Object*> objects;
};

#endif
