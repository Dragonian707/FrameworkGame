#include <fstream>
#include <sstream>

#include "object.h"



Object::Object(std::string filePath)
{
	texture = ResourceManager::Instance()->GetTexture(filePath);
	color = WHITE;

	position = Vector2(0.0f, 0.0f);
	rotation = 0.0f;
	scale = 1.0;
}

Object::~Object()
{
	UnloadTexture(texture);
}

void Object::Draw()
{
	Rectangle sourceRec = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
	Rectangle destRec = { position.x, position.y, (float)texture.width * scale, (float)texture.height * scale };
	Vector2 origin = { texture.width / 2, texture.height / 2 };

	DrawTexturePro(texture, sourceRec, destRec, origin, rotation, color);
}