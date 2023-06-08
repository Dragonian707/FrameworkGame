#include <fstream>
#include <sstream>

#include "testscene.h"
#include "textsprite.h"



TestScene::TestScene()
{
	spike = new Spike(true, Vector2(SCRWIDTH + 100, SCRHEIGHT + 100));
	AddObject(spike);

	TextSprite* text = new TextSprite;
	text->position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2);
	text->SetMessage("See you later fucker!");
	AddObject(text);
}

TestScene::~TestScene()
{
	delete spike;
	spike = nullptr;
}

void TestScene::update(float deltaTime)
{
	if (spike->dead && spike != nullptr)
	{
		DeleteObject(spike);
		spike = nullptr;
	}
	if (spike == nullptr)
	{
		spike = new Spike(true, Vector2(SCRWIDTH + 100, SCRHEIGHT / 2));
		AddObject(spike);
	}
}