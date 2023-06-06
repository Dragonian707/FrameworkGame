#ifndef SPIKE_H
#define SPIKE_H

#include "raylib.h"
#include "drawsprite.h"
#include <vector>

class Spike : public DrawSprite
{
public:
	/// @brief Constructor
	Spike();
	/// @brief Destructor
	virtual ~Spike();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	//void CheckBorders();
	int speed;
};

#endif
