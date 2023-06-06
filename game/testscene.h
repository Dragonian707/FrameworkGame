#ifndef TESTSCENE_H
#define TESTSCENE_H

#include "scene.h"
#include "spike.h"

class TestScene : public Scene
{
public:
	/// @brief Constructor
	TestScene();
	/// @brief Destructor
	virtual ~TestScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Spike* spike;
};

#endif
