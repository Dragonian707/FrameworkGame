#ifndef SPIKE_H
#define SPIKE_H

#include "raylib.h"
#include "drawsprite.h"
#include <vector>

class Spike : public DrawSprite
{
public:
	/// @brief Constructor
	Spike(bool toMouse, Vector2 pos, Color col);
	/// @brief Destructor
	virtual ~Spike();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	bool dead = false;
	bool paused = false;
	int speed;

private:
	//void CheckBorders();
	float lifeforce;
	float timer;
	void PointToMouse();
	void Move(float deltatime);
};

#endif
