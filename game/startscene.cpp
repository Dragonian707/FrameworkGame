#include <fstream>
#include <sstream>

#include "startscene.h"



StartScene::StartScene()
{
	activescene = 0;
	startbutton = new Button("Start Game", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2 - 100));
	AddObject(startbutton);
	startbutton->SetMethod(std::bind(&StartScene::StartGame, this));

	quitbutton = new Button("Exit", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2 + 100));
	AddObject(quitbutton);
	quitbutton->SetMethod(std::bind(&StartScene::CloseGame, this));

	optionbutton = new Button("Options", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2));
	AddObject(optionbutton);
	optionbutton->SetMethod(std::bind(&StartScene::OpenOptions, this));

	backtrack = ResourceManager::Instance()->GetMusic("assets/menu_music.ogg");
	PlayMusicStream(backtrack);
}

StartScene::~StartScene()
{
	DeleteObject(startbutton);
	DeleteObject(quitbutton);
}

void StartScene::update(float deltaTime)
{
	UpdateMusicStream(backtrack);
}

void StartScene::StartGame()
{
	activescene = 1;
}

void StartScene::OpenOptions()
{
	activescene = 2;
}