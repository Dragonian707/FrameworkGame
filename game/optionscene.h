#ifndef OPTIONSCENE_H
#define OPTIONSCENE_H

#include "scene.h"
#include "button.h"
#include "textsprite.h"

class OptionScene : public Scene
{
public:
	/// @brief Constructor
	OptionScene(int prevScene);
	/// @brief Destructor
	virtual ~OptionScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Button* backButton;

	TextSprite* optiontext;

	Music backtrack;

	int previous;

	void CloseOptions();

	void SpeedOption();
	void TimingOption();
	void PatternOption();
	void ColorOption();
	//void MusicOption();
	void ReturnButtons();

	bool first = true;
	bool deciding = false;
	bool speed = false;
	bool timing = false;
	bool pattern = false;
	bool coloring = false;

	std::string speedAmount;
	std::string timingAmount;
	std::string patternAmount;

	Button* OpenSpeed;
	Button* OpenTiming;
	Button* OpenPattern;
	Button* OpenColor;

	std::vector<Button*> buttons;

	std::vector<std::string> colors = {"Blue", "Red", "Green", "Yellow", "Purple", "White", "Brown", "Orange", "Pink", "Lime", "Violet", "Gray"};
	std::vector<Button*> colorButtons;
	void CreateColorButtons();
	void DeleteColorButtons();
	void SetColor(int collumn, std::string colorToSet);

	std::string playerColor;
	std::string patternColor;
	std::string spikeColor;
};

#endif
