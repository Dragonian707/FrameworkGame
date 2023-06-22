#include <fstream>
#include <sstream>

#include "button.h"



Button::Button(std::string bt, Vector2 pos) : DrawSprite("assets/button.png")
{
	position = pos;
	buttontext = new TextSprite();
	buttontext->SetMessage(bt);
	buttontext->position = position;
	buttontext->color = WHITE;
}

Button::~Button()
{
	delete buttontext;
	buttontext = nullptr;
}

void Button::update(float deltaTime)
{
	Vector2 mpos = GetMousePosition();
	float texwidhalf = texture.width / 2;
	float texheihalf = texture.height / 2;

	if (mpos.x >= position.x - texwidhalf && mpos.x <= position.x + texwidhalf && mpos.y >= position.y - texheihalf && mpos.y <= position.y + texheihalf)
	{
		color = GREEN;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (methodToDo == NULL)
			{
				return;
			}
			methodToDo();
		}
	}
	else
	{
		color = WHITE;
	}


	buttontext->UpdateObject(deltaTime);
}

void Button::SetMethod(std::function<void()> method)
{
	methodToDo = method;
}