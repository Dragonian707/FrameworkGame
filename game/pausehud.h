#ifndef PAUSEHUD_H
#define PAUSEHUD_H

#include "drawsprite.h"
#include "textsprite.h"
#include "button.h"

class PauseHud : public DrawSprite
{
public:
	/// @brief Constructor
	PauseHud();
	/// @brief Destructor
	virtual ~PauseHud();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	enum State { nothing, resume, restart, options, exit };
	State state = nothing;
private:
	TextSprite* pausedText;
	float timer;

	Button* Resume;
	Button* Reset;
	Button* Quit;
	Button* Options;

	void ResumeGame();
	void ResetGame();
	void ExitGame();
	void OpenOptions();
};

#endif
