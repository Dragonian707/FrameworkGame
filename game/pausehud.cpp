#include <fstream>
#include <sstream>

#include "pausehud.h"



PauseHud::PauseHud() : DrawSprite("assets/pausehud.png")
{
	position = Vector2(SCRWIDTH / 2, SCRHEIGHT / 2);
	timer = 0;

	pausedText = new TextSprite();
	pausedText->SetMessage("PAUSED");
	pausedText->position = Vector2(SCRWIDTH / 2, -50);

	Resume = new Button("Resume", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2 - 100));
	Resume->SetMethod(std::bind(&PauseHud::ResumeGame, this));

	Reset = new Button("Restart", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2));
	Reset->SetMethod(std::bind(&PauseHud::ResetGame, this));

	Quit = new Button("Exit", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2 + 100));
	Quit->SetMethod(std::bind(&PauseHud::ExitGame, this));
}

PauseHud::~PauseHud()
{
	delete pausedText;
	pausedText = nullptr;
}

void PauseHud::update(float deltaTime)
{
	pausedText->UpdateObject(deltaTime);
	Resume->UpdateObject(deltaTime);
	Reset->UpdateObject(deltaTime);
	Quit->UpdateObject(deltaTime);

	if (timer >= 1)
	{
		pausedText->position.y = 50;
		timer = 0;
	}
	else if (timer >= 0.5)
	{
		pausedText->position.y = -50;
	}
	timer += deltaTime;
}

void PauseHud::ResumeGame()
{
	state = resume;
}
void PauseHud::ResetGame()
{
	state = restart;
}
void PauseHud::ExitGame()
{
	state = exit;
}