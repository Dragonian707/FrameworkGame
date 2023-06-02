#include <fstream>
#include <sstream>

#include "testscene.h"
#include "testobj.h"



TestScene::TestScene()
{
	i = new TestOBJ("assets/test.png");
	i->position = Vector2(SCRWIDTH / 4, SCRHEIGHT / 2);
	AddObject(i);

	j = new TestOBJ("assets/nonexisting.png");
	j->position = Vector2(SCRWIDTH / 4 * 3, SCRHEIGHT / 2);
	AddObject(j);
}

TestScene::~TestScene()
{
	
}

void TestScene::update(float deltaTime)
{
	i->rotation += 360 * deltaTime;
}