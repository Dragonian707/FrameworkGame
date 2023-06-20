#include <fstream>
#include <sstream>

#include "spawner.h"



//Spawner::Spawner(Scene* s)
//{
//	//scene = s;
//	srand(time(NULL));
//}

Spawner::Spawner()
{
	//scene = s;
	srand(time(NULL));
}

Spawner::~Spawner()
{

}

std::vector<Spike*> Spawner::Spawn(bool pattern)
{
	std::vector<Spike*> spikes;

	if (pattern)
	{
		spikes = Pattern(rand() % 10);
		return spikes;
	}

	int place = rand() % 4;

	int x = 0;
	int y = 0;

	switch (place)
	{
	case 0:
		x = -100;
		y = rand() % SCRHEIGHT;
		break;
	case 1:
		x = rand() % SCRWIDTH;
		y = -100;
		break;
	case 2:
		x = SCRWIDTH + 100;
		y = rand() % SCRHEIGHT;
		break;
	case 3:
		x = rand() % SCRWIDTH;
		y = SCRHEIGHT + 100;
		break;
	}

	Spike* s = new Spike(true, Vector2(x, y));
	s->speed += rand() % 100;
	spikes.push_back(s);

	return spikes;
}

std::vector<Spike*> Spawner::Pattern(int pattern)
{
	std::vector<Spike*> spikes;

	Spike* one;
	Spike* two;
	Spike* three;
	Spike* four;
	Spike* five;
	Spike* six;

	switch (pattern)
	{
	case 0: //square pattern
		one = new Spike(false, Vector2(-100, 150));
		one->rotation = 0; //point to right
		two = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT - 150));
		two->rotation = 180; //point to left
		three = new Spike(false, Vector2(SCRWIDTH - 150, -100));
		three->rotation = 90; //point down
		four = new Spike(false, Vector2(150, SCRHEIGHT + 100));
		four->rotation = 270; //point up

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		break;
	case 1: //diamond pattern
		one = new Spike(false, Vector2(-50, SCRHEIGHT / 2));
		one->rotation = 45; //point to bottomright
		two = new Spike(false, Vector2(SCRWIDTH + 50, SCRHEIGHT / 2));
		two->rotation = 225; //point to topleft
		three = new Spike(false, Vector2(SCRWIDTH / 2, -50));
		three->rotation = 135; //point bottomleft
		four = new Spike(false, Vector2(SCRWIDTH / 2, SCRHEIGHT + 50));
		four->rotation = 315; //point topright

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		break;
	case 2: //square reversed
		one = new Spike(false, Vector2(150, -100));
		one->rotation = 90; //point down
		two = new Spike(false, Vector2(SCRWIDTH - 150, SCRHEIGHT + 100));
		two->rotation = 270; //point up
		three = new Spike(false, Vector2(SCRWIDTH + 100, 150));
		three->rotation = 180; //point left
		four = new Spike(false, Vector2(-100, SCRHEIGHT - 150));
		four->rotation = 0; //point right

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		break;
	case 3: //diamond reversed
		one = new Spike(false, Vector2(-50, SCRHEIGHT / 2));
		one->rotation = 315; //point to bottomleft
		two = new Spike(false, Vector2(SCRWIDTH + 50, SCRHEIGHT / 2));
		two->rotation = 135; //point to topright
		three = new Spike(false, Vector2(SCRWIDTH / 2, -50));
		three->rotation = 45; //point topleft
		four = new Spike(false, Vector2(SCRWIDTH / 2, SCRHEIGHT + 50));
		four->rotation = 225; //point bottomright

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		break;
	case 4: //bars vertical
		one = new Spike(false, Vector2(100, -100));
		one->rotation = 90; //point down
		two = new Spike(false, Vector2(SCRWIDTH / 2, SCRHEIGHT + 100));
		two->rotation = 270; //point up
		three = new Spike(false, Vector2(SCRWIDTH -100, -100));
		three->rotation = 90; //point down

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		break;
	case 5: //bars horizontal
		one = new Spike(false, Vector2(-100, 100));
		one->rotation = 0; //point right
		two = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT / 2));
		two->rotation = 180; //point to left
		three = new Spike(false, Vector2(-100, SCRHEIGHT - 100));
		three->rotation = 0; //point right

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		break;
	case 6: //'star' pattern
		one = new Spike(false, Vector2(-100, SCRHEIGHT / 2));
		one->rotation = 0; //point right from middle
		two = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT / 2));
		two->rotation = 180; //point to left from middle
		three = new Spike(false, Vector2(SCRWIDTH / 4, -100));
		three->rotation = 45; //point to bottomright
		four = new Spike(false, Vector2(SCRWIDTH / 4 * 3, SCRHEIGHT + 100));
		four->rotation = 225; //point to topleft
		five = new Spike(false, Vector2(SCRWIDTH / 4 * 3, -100));
		five->rotation = 135; //point to bottomleft
		six = new Spike(false, Vector2(SCRWIDTH / 4, SCRHEIGHT + 100));
		six->rotation = 315; //point topright

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		spikes.push_back(six);
		break;
	case 7: //'star' pattern turned
		one = new Spike(false, Vector2(SCRWIDTH / 2, -100));
		one->rotation = 90; //point down from middle
		two = new Spike(false, Vector2(SCRWIDTH / 2, SCRHEIGHT + 100));
		two->rotation = 270; //point up from middle
		three = new Spike(false, Vector2(-100, SCRHEIGHT / 4));
		three->rotation = 45; //point to bottomright
		four = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT / 4 * 3));
		four->rotation = 225; //point to topleft
		five = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT / 4));
		five->rotation = 135; //point to bottomleft
		six = new Spike(false, Vector2(-100, SCRHEIGHT / 4 * 3));
		six->rotation = 315; //point topright

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		spikes.push_back(six);
		break;
	case 8: //from top point to middle
		one = new Spike(false, Vector2(SCRWIDTH / 2, -225));
		one->rotation = 90; //point down from middle
		two = new Spike(false, Vector2(SCRWIDTH / 4, -195));
		two->rotation = 72.5f; //point slightly to bottomright
		three = new Spike(false, Vector2(SCRWIDTH / 4 * 3, -195));
		three->rotation = 107.5f; //point slightly to bottomleft
		four = new Spike(false, Vector2(-50, -50));
		four->rotation = 45; //point to bottomright
		five = new Spike(false, Vector2(SCRWIDTH + 50, -50));
		five->rotation = 135; //point to bottomleft

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		break;
	case 9: //from left point to middle
		one = new Spike(false, Vector2(-225, SCRHEIGHT / 2));
		one->rotation = 0; //point down from middle
		two = new Spike(false, Vector2(-195, SCRHEIGHT / 4));
		two->rotation = 17.5f; //point slightly to bottomright
		three = new Spike(false, Vector2(-195, SCRHEIGHT / 4 *3));
		three->rotation = 342.5f; //point slightly to topright
		four = new Spike(false, Vector2(-50, -50));
		four->rotation = 45; //point to bottomright
		five = new Spike(false, Vector2(-50, SCRHEIGHT + 50));
		five->rotation = 315; //point to topright

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		break;
	}

	return spikes;
}