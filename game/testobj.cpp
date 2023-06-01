#include <fstream>
#include <sstream>

#include "testobj.h"



TestOBJ::TestOBJ(std::string filePath) : SpriteObject(filePath)
{
	
}

TestOBJ::~TestOBJ()
{

}

void TestOBJ::update(float deltatime)
{
	this->rotation += 360 * deltatime;
}

