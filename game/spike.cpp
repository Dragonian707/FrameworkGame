#include <fstream>
#include <sstream>

#include "spike.h"



Spike::Spike(bool toMouse, Vector2 pos, Color col) : DrawSprite("assets/spike.png")
{
	std::ifstream option("options.txt");
	std::vector<std::string> s;
	std::string temp;
	while (std::getline(option, temp, ':'))
	{
		s.push_back(temp);
	}

	if (!s.empty()) 
	{ 
		int sp = std::stoi(s[1]);
		if (sp > 1000) { sp = 1000; };
		if (sp < 10) { sp = 10; };
		speed = sp;
	}
	else
	{
		speed = 400;
	}

	lifeforce = 5;
	timer = 0;
	position = pos;
	color = col;
	if (toMouse)
	{
		PointToMouse();
	}
}

Spike::~Spike()
{
	
}

void Spike::update(float deltatime)
{
	if (!paused)
	{
		Move(deltatime);
		timer += deltatime;
	}
	if (timer >= lifeforce && (position.x < -50 || position.x > SCRWIDTH + 50 || position.y < -50 || position.y > SCRHEIGHT + 50))
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