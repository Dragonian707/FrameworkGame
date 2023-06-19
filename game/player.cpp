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
	Move(deltatime);
}

void Player::Move(float deltatime)
{
	position = GetMousePosition();
}