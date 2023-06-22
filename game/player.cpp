#include <fstream>
#include <sstream>

#include "player.h"



Player::Player() : DrawSprite("assets/player.png")
{
	scale = 0.3f;
}

Player::~Player()
{

}

void Player::update(float deltatime)
{
	if (paused)
	{
		ready = false;
	}
	if (ready)
	{
		Move(deltatime);
	}

	if (dead)
	{
		color = BLACK;
	}
}

void Player::Move(float deltatime)
{
	position = GetMousePosition();
}

bool Player::CheckReady()
{
	ready = false;
	if (Vector2Distance(position, GetMousePosition()) <= texture.width * scale && !paused)
	{
		HideCursor();
		ready = true;
	}
	return ready;
}