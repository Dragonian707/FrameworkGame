#ifndef TESTOBJ_H
#define TESTOBJ_H

#include "raylib.h"
#include "spriteobject.h"
#include <vector>

class TestOBJ : public SpriteObject
{
public:
	/// @brief Constructor
	TestOBJ(std::string filePath);
	/// @brief Destructor
	virtual ~TestOBJ();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:

};

#endif
