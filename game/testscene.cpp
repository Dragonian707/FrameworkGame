#include <fstream>
#include <sstream>

#include "testscene.h"
//#include "spike.h"



TestScene::TestScene()
{
	spike = new Spike();
	AddObject(spike);
}

TestScene::~TestScene()
{
	
}

void TestScene::update(float deltaTime)
{
	
}