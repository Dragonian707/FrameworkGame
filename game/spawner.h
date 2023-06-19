#ifndef SPAWNER_H
#define SPAWNER_H

#include "raylib.h"
#include "sprite.h"
//#include "testscene.h"
//#include "scene.h"
#include "spike.h"
#include <vector>

//class TestScene;

class Spawner
{
public:
	/// @brief Constructor
	//Spawner(Scene* s);
	Spawner();
	/// @brief Destructor
	virtual ~Spawner();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	//virtual void update(float deltaTime);

	//Spike* Spawn(bool pattern);
	std::vector<Spike*> Spawn(bool pattern);
private:
	//virtual void UpdateObject(float deltatime);

	std::vector<Spike*> Pattern(int pattern);

	//Scene* scene;
};

#endif
