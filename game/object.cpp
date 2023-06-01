#include <fstream>
#include <sstream>

#include "object.h"



Object::Object()
{
	position = Vector2(0.0f, 0.0f);
	rotation = 0.0f;
	scale = 1.0;
}

Object::~Object()
{
	
}