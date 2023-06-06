#include <fstream>
#include <sstream>

#include "spike.h"



Spike::Spike() : DrawSprite("assets/spike.png")
{
	speed = 100;
	position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2);
}

Spike::~Spike()
{

}

void Spike::update(float deltatime)
{
	/*-----------------point towards mouse--------------------------------------
	Vector2 mousepos = GetMousePosition();
	Vector2 lookPos = Vector2(position.x - mousepos.x, position.y - mousepos.y);
	rotation = atan2(lookPos.y, lookPos.x) * RAD2DEG - 90;*/

	
}

