#include <fstream>
#include <sstream>

#include "testobj.h"



TestOBJ::TestOBJ(std::string filePath) : SpriteObject(filePath)
{
	speed = Vector2(100, 200);
}

TestOBJ::~TestOBJ()
{

}

void TestOBJ::update(float deltatime)
{
	position = Vector2(position.x + speed.x * deltatime, position.y + speed.y * deltatime);
	CheckBorders();
}

void TestOBJ::CheckBorders()
{
	if (position.x <= 0 + texture.width / 2 || position.x >= SCRWIDTH - texture.width / 2)
	{
		speed.x *= -1;
	}
	if (position.y <= 0 + texture.height / 2 || position.y >= SCRHEIGHT - texture.height / 2)
	{
		speed.y *= -1;
	}
}

