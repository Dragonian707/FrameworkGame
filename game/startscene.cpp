#include <fstream>
#include <sstream>

#include "startscene.h"



StartScene::StartScene()
{
	activescene = 0;
	startbutton = new Button("Start Game", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2 - 50));
	AddObject(startbutton);
	startbutton->SetMethod(std::bind(&StartScene::StartGame, this));

	quitbutton = new Button("Exit", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2 + 50));
	AddObject(quitbutton);
	quitbutton->SetMethod(std::bind(&StartScene::CloseGame, this));
}

StartScene::~StartScene()
{
	DeleteObject(startbutton);
	DeleteObject(quitbutton);
}

void StartScene::update(float deltaTime)
{
	
}

void StartScene::StartGame()
{
	activescene++;
}