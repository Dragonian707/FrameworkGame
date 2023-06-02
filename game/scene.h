#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"
#include "object.h"
#include <vector>

class Scene : public Object
{
public:
	/// @brief Constructor
	Scene();
	/// @brief Destructor
	virtual ~Scene();

	void AddObject(Object* object);

	virtual void UpdateObject(float deltatime);

private:
	std::vector<Object*> objects;
};

#endif
