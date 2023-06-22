#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "drawsprite.h"
#include <vector>

class Player : public DrawSprite
{
public:
	/// @brief Constructor
	Player();
	/// @brief Destructor
	virtual ~Player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	bool dead = false;
	bool paused = false;
	bool ready = true;

	bool CheckReady();

private:
	void Move(float deltatime);
};

#endif
