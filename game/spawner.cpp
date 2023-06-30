#include <fstream>
#include <sstream>

#include "spawner.h"


Spawner::Spawner()
{
	srand(time(NULL));
	ParseColors();
}

Spawner::~Spawner()
{

}

std::vector<Spike*> Spawner::Spawn(bool pattern)
{
	std::vector<Spike*> spikes;

	if (pattern)
	{
		spikes = Pattern(rand() % 11);
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

	Spike* s = new Spike(true, Vector2(x, y), BLUE); //error
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
	{
		one = new Spike(false, Vector2(-100, 150), PatternColor);
		one->rotation = 0; //point to right
		two = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT - 150), PatternColor);
		two->rotation = 180; //point to left
		three = new Spike(false, Vector2(SCRWIDTH - 150, -100), PatternColor);
		three->rotation = 90; //point down
		four = new Spike(false, Vector2(150, SCRHEIGHT + 100), PatternColor);
		four->rotation = 270; //point up

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four); 
		break;
	}
	case 1: //diamond pattern
	{
		one = new Spike(false, Vector2(-50, SCRHEIGHT / 2), PatternColor);
		one->rotation = 45; //point to bottomright
		two = new Spike(false, Vector2(SCRWIDTH + 50, SCRHEIGHT / 2), PatternColor);
		two->rotation = 225; //point to topleft
		three = new Spike(false, Vector2(SCRWIDTH / 2, -50), PatternColor);
		three->rotation = 135; //point bottomleft
		four = new Spike(false, Vector2(SCRWIDTH / 2, SCRHEIGHT + 50), PatternColor);
		four->rotation = 315; //point topright

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		break;
	}
	case 2: //delayed doubles
	{
		one = new Spike(false, Vector2(SCRWIDTH / 4, -100), PatternColor);
		one->rotation = 90; //point down
		two = new Spike(false, Vector2(SCRWIDTH / 2, -300), PatternColor);
		two->rotation = 90; //point down
		three = new Spike(false, Vector2(SCRWIDTH / 4 * 3, -500), PatternColor);
		three->rotation = 90; //point down

		four = new Spike(false, Vector2(SCRWIDTH + 500, SCRHEIGHT / 4), PatternColor);
		four->rotation = 180; //point left
		five = new Spike(false, Vector2(SCRWIDTH + 300, SCRHEIGHT / 2), PatternColor);
		five->rotation = 180; //point left
		six = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT / 4 * 3), PatternColor);
		six->rotation = 180; //point left

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		spikes.push_back(six);
		break;
	}
	case 3: //double 'explode'
	{
		one = new Spike(false, Vector2(-50, SCRHEIGHT + 50), PatternColor);
		one->rotation = 315; //point to topright
		two = new Spike(false, Vector2(-50, SCRHEIGHT + 50), PatternColor);
		two->rotation = 280; //point mostly up
		three = new Spike(false, Vector2(-50, SCRHEIGHT + 50), PatternColor);
		three->rotation = 297.5f; //point between one & two

		four = new Spike(false, Vector2(SCRWIDTH + 50, -50), PatternColor);
		four->rotation = 135; //point bottomleft
		five = new Spike(false, Vector2(SCRWIDTH + 50, -50), PatternColor);
		five->rotation = 100; //point bottomright
		six = new Spike(false, Vector2(SCRWIDTH + 50, -50), PatternColor);
		six->rotation = 117.5f; //point bottomright

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		spikes.push_back(six);
		break;
	}	
	case 4: //bars vertical
	{
		one = new Spike(false, Vector2(100, -100), PatternColor);
		one->rotation = 90; //point down
		two = new Spike(false, Vector2(SCRWIDTH / 2, SCRHEIGHT + 100), PatternColor);
		two->rotation = 270; //point up
		three = new Spike(false, Vector2(SCRWIDTH - 100, -100), PatternColor);
		three->rotation = 90; //point down

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		break;
	}
	case 5: //bars horizontal
	{
		one = new Spike(false, Vector2(-100, 100), PatternColor);
		one->rotation = 0; //point right
		two = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT / 2), PatternColor);
		two->rotation = 180; //point to left
		three = new Spike(false, Vector2(-100, SCRHEIGHT - 100), PatternColor);
		three->rotation = 0; //point right

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		break;
	}
	case 6: //'star' pattern
	{
		one = new Spike(false, Vector2(-100, SCRHEIGHT / 2), PatternColor);
		one->rotation = 0; //point right from middle
		two = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT / 2), PatternColor);
		two->rotation = 180; //point to left from middle
		three = new Spike(false, Vector2(SCRWIDTH / 4, -100), PatternColor);
		three->rotation = 45; //point to bottomright
		four = new Spike(false, Vector2(SCRWIDTH / 4 * 3, SCRHEIGHT + 100), PatternColor);
		four->rotation = 225; //point to topleft
		five = new Spike(false, Vector2(SCRWIDTH / 4 * 3, -100), PatternColor);
		five->rotation = 135; //point to bottomleft
		six = new Spike(false, Vector2(SCRWIDTH / 4, SCRHEIGHT + 100), PatternColor);
		six->rotation = 315; //point topright

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		spikes.push_back(six);
		break;
	}
	case 7: //'star' pattern turned
	{
		one = new Spike(false, Vector2(SCRWIDTH / 2, -100), PatternColor);
		one->rotation = 90; //point down from middle
		two = new Spike(false, Vector2(SCRWIDTH / 2, SCRHEIGHT + 100), PatternColor);
		two->rotation = 270; //point up from middle
		three = new Spike(false, Vector2(-100, SCRHEIGHT / 4), PatternColor);
		three->rotation = 45; //point to bottomright
		four = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT / 4 * 3), PatternColor);
		four->rotation = 225; //point to topleft
		five = new Spike(false, Vector2(SCRWIDTH + 100, SCRHEIGHT / 4), PatternColor);
		five->rotation = 135; //point to bottomleft
		six = new Spike(false, Vector2(-100, SCRHEIGHT / 4 * 3), PatternColor);
		six->rotation = 315; //point topright

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		spikes.push_back(six);
		break;
	}
	case 8: //from top point to middle
	{
		one = new Spike(false, Vector2(SCRWIDTH / 2, -100), PatternColor);
		one->rotation = 90; //point down from middle

		two = new Spike(false, Vector2(SCRWIDTH / 4 - 4, -92.4), PatternColor);
		two->rotation = 67.5f; //point slightly to bottomright
		float s = Vector2Distance(two->position, Vector2(SCRWIDTH / 2, SCRHEIGHT / 2));
		s = s / (500.0f / one->speed);
		two->speed = s;
		three = new Spike(false, Vector2(SCRWIDTH / 4 * 3 + 4, -92.4), PatternColor);
		three->rotation = 112.5f; //point slightly to bottomleft
		three->speed = s;

		four = new Spike(false, Vector2(-70.7f, -70.7f), PatternColor);
		four->rotation = 45; //point to bottomright
		s = Vector2Distance(four->position, Vector2(SCRWIDTH / 2, SCRHEIGHT / 2));
		s = s / (500.0f / one->speed);
		four->speed = s;
		five = new Spike(false, Vector2(SCRWIDTH + 70.7f, -70.7f), PatternColor);
		five->rotation = 135; //point to bottomleft
		five->speed = s;

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		break;
	}
	case 9: //from left point to middle
	{
		one = new Spike(false, Vector2(-100, SCRHEIGHT / 2), PatternColor);
		one->rotation = 0; //point right from middle

		two = new Spike(false, Vector2(-92.4, SCRHEIGHT / 4 - 4), PatternColor);
		two->rotation = 22.5f; //point slightly to bottomright
		float s = Vector2Distance(two->position, Vector2(SCRWIDTH / 2, SCRHEIGHT / 2));
		s = s / (500.0f / one->speed);
		two->speed = s;
		three = new Spike(false, Vector2(-92.4, SCRHEIGHT / 4 * 3 + 4), PatternColor);
		three->rotation = 337.5f; //point slightly to topright
		three->speed = s;

		four = new Spike(false, Vector2(-70.7f, -70.7f), PatternColor);
		four->rotation = 45; //point to bottomright
		s = Vector2Distance(four->position, Vector2(SCRWIDTH / 2, SCRHEIGHT / 2));
		s = s / (500.0f / one->speed);
		four->speed = s;
		five = new Spike(false, Vector2(-70.7f, SCRHEIGHT + 70.7f), PatternColor);
		five->rotation = 315; //point to topright
		five->speed = s;

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		break;
	}
	case 10: //explode from bottomright
	{
		one = new Spike(false, Vector2(SCRWIDTH + 50, SCRHEIGHT + 50), PatternColor);
		one->rotation = 225; //point to opposite corner
		two = new Spike(false, Vector2(SCRWIDTH + 50, SCRHEIGHT + 50), PatternColor);
		two->rotation = 200; //point mostly left
		three = new Spike(false, Vector2(SCRWIDTH + 50, SCRHEIGHT + 50), PatternColor);
		three->rotation = 250; //point mostly up
		four = new Spike(false, Vector2(SCRWIDTH + 50, SCRHEIGHT + 50), PatternColor);
		four->rotation = 212.5f; //point between one & two
		five = new Spike(false, Vector2(SCRWIDTH + 50, SCRHEIGHT + 50), PatternColor);
		five->rotation = 237.5f; //point between one & three

		spikes.push_back(one);
		spikes.push_back(two);
		spikes.push_back(three);
		spikes.push_back(four);
		spikes.push_back(five);
		break;
	}
	}

	return spikes;
}

void Spawner::ParseColors()
{
	//getting options from options.txt
	std::ifstream option("options.txt");
	std::vector<std::string> s;
	std::string temp;
	while (std::getline(option, temp, ':'))
	{
		s.push_back(temp);
		//std::cout << temp << std::endl; // every three give a new value
	}

	if (!s.empty())
	{
		PlayerColor = colors[s[10]];
		SpikeColor = colors[s[13]];
		PatternColor = colors[s[16]];
	}
}