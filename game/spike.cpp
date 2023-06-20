#include <fstream>
#include <sstream>

#include "spike.h"



Spike::Spike(bool toMouse, Vector2 pos) : DrawSprite("assets/spike.png")
{
	speed = 400;
	lifeforce = 5;
	timer = 0;
	position = pos;
	color = DARKBLUE;
	if (toMouse)
	{
		color = RED;
		PointToMouse();
	}
}

Spike::~Spike()
{
	//std::cout << "I ded\n";
}

void Spike::update(float deltatime)
{
	Move(deltatime);
	timer += deltatime;
	if (timer >= lifeforce)
	{
		dead = true;
	}
}

void Spike::PointToMouse()
{
	Vector2 mousepos = GetMousePosition();
	Vector2 lookPos = Vector2(mousepos.x - position.x, mousepos.y - position.y);
	rotation = atan2(lookPos.y, lookPos.x) * RAD2DEG;
}

void Spike::Move(float deltatime)
{
	//move forward
	float x = cos(rotation * DEG2RAD);
	float y = sin(rotation * DEG2RAD);

	Vector2 velocity = Vector2(x, y);
	Vector2Normalize(velocity);
	
	position = Vector2Add(position, Vector2(velocity.x * speed * deltatime, velocity.y * speed * deltatime));
}