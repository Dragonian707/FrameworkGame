#ifndef OBJECT_H
#define OBJECT_H

#include "raylib.h"
#include "resourcemanager.h"
#include <vector>

#include "settings.h"

class Object
{
public:
	/// @brief Constructor
	Object();
	/// @brief Destructor
	virtual ~Object();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime) = 0;

	virtual void UpdateObject(float deltatime) = 0;

	//position rotation and scale
	Vector2 position;
	float rotation;
	float scale;

private:

};

#endif
