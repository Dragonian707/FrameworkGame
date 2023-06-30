#include <fstream>
#include <sstream>

#include "optionscene.h"



OptionScene::OptionScene(int prevScene)
{
	activescene = 2;
	previous = prevScene;
	//----------------------------------------get current options from option file---------------------
	std::ifstream option("options.txt");
	std::vector<std::string> s;
	std::string temp;
	while (std::getline(option, temp, ':'))
	{
		s.push_back(temp);
		std::cout << temp << std::endl; // every three gives a new value, starting at 1
	}
	if (s.size() >= 18)
	{
		speedAmount = s[1];
		timingAmount = s[4];
		patternAmount = s[7];

		playerColor = s[10];
		spikeColor = s[13];
		patternColor = s[16];
	}
	else
	{
		speedAmount = "400";
		timingAmount = "500";
		patternAmount = "20";

		playerColor = "Green";
		spikeColor = "Red";
		patternColor = "Blue";
	}
	//-------------------------------------------------------------------------------------------------
	//-------------------------------create, add and assign all buttons as options---------------------
	optiontext = new TextSprite();
	optiontext->SetMessage("");
	optiontext->position = Vector2(SCRWIDTH / 2, 30);
	AddObject(optiontext);

	backtrack = ResourceManager::Instance()->GetMusic("assets/menu_music.ogg");
	PlayMusicStream(backtrack);
	
	//back to previous scene
	backButton = new Button("Close Options", Vector2(SCRWIDTH / 2, SCRHEIGHT - 50));
	backButton->SetMethod(std::bind(&OptionScene::CloseOptions, this));
	AddObject(backButton);

	//set speed option
	OpenSpeed = new Button("Spike Speed", Vector2(SCRWIDTH / 2 - 270, SCRHEIGHT / 2 - 50));
	OpenSpeed->SetMethod(std::bind(&OptionScene::SpeedOption, this));
	AddObject(OpenSpeed);

	//set spawndelay option
	OpenTiming = new Button("Spawn Delay", Vector2(SCRWIDTH / 2, SCRHEIGHT / 2 - 50));
	OpenTiming->SetMethod(std::bind(&OptionScene::TimingOption, this));
	AddObject(OpenTiming);

	//set patternchance option
	OpenPattern = new Button("Pattern Chance", Vector2(SCRWIDTH / 2 + 270, SCRHEIGHT / 2 - 50));
	OpenPattern->SetMethod(std::bind(&OptionScene::PatternOption, this));
	AddObject(OpenPattern);

	//set color options
	OpenColor = new Button("Cheng Colors", Vector2(SCRWIDTH / 2 - 270, SCRHEIGHT / 2 + 50));
	OpenColor->SetMethod(std::bind(&OptionScene::ColorOption, this));
	AddObject(OpenColor);

	//add all buttons to list to 're'move them all
	buttons.push_back(backButton);
	buttons.push_back(OpenSpeed);
	buttons.push_back(OpenTiming);
	buttons.push_back(OpenPattern);
	buttons.push_back(OpenColor);
	//-------------------------------------------------------------------------------------------------
}

OptionScene::~OptionScene()
{
	DeleteObject(backButton);
	std::ofstream file ("options.txt");

	if (speedAmount.empty()) { speedAmount = "400"; };
	if (timingAmount.empty()) { timingAmount = "500"; };
	if (patternAmount.empty()) { patternAmount = "20"; };

	if (playerColor.empty()) { playerColor = "Green"; };
	if (spikeColor.empty()) {spikeColor = "Red"; };
	if (patternColor.empty()) { patternColor = "Blue"; };

	if (file.is_open())
	{
		file << "speed:" << speedAmount << ":\n:"; //give speed option to file
		file << "waveTiming:" << timingAmount << ":\n:"; //give spawn delay to file
		file << "patternChance:" << patternAmount << ":\n:"; //give pattern chance to file

		file << "playerColor:" << playerColor << ":\n:"; //give player color to file
		file << "spikeColor:" << spikeColor << ":\n:"; //give spike color to file
		file << "patternColor:" << patternColor << ":\n:"; //give pattern color to file

		file.close();
	}
	else
	{
		std::cout << "could not open file\n";
	}
}

void OptionScene::SpeedOption()
{
	deciding = true;
	speed = true;
}
void OptionScene::TimingOption()
{
	deciding = true;
	timing = true;
}
void OptionScene::PatternOption()
{
	deciding = true;
	pattern = true;
}
void OptionScene::ColorOption()
{
	deciding = true;
	coloring = true;
	CreateColorButtons();
}

void OptionScene::update(float deltaTime)
{
	UpdateMusicStream(backtrack);

	if (!deciding) { return; };

	if (first)
	{
		for (Button* b : buttons)
		{
			b->position.x -= SCRWIDTH;
		}
		if (speed) { speedAmount = ""; };
		if (timing) { timingAmount = ""; };
		if (pattern) { patternAmount = ""; };
		first = false;
	}

	if (speed)
	{
		int i = GetKeyPressed();
		if (i >= 48 && i <= 57)
		{
			i -= 48;
			speedAmount += std::to_string(i); //add any number to the speedAmount string
		}

		std::string ms = "";
		ms += "Speed = ";
		ms += speedAmount;
		ms += "		default is 400";
		optiontext->SetMessage(ms);
	}
	if (timing)
	{
		int i = GetKeyPressed();
		if (i >= 48 && i <= 57)
		{
			i -= 48;
			timingAmount += std::to_string(i); //add any number to the speedAmount string
		}

		std::string ms = "";
		ms += "Speed = ";
		ms += timingAmount;
		ms += "ms		default is 500ms";
		optiontext->SetMessage(ms);
	}
	if (pattern)
	{
		int i = GetKeyPressed();
		if (i >= 48 && i <= 57)
		{
			i -= 48;
			patternAmount += std::to_string(i); //add any number to the patternAmount string
		}

		std::string ms = "";
		ms += "Pattern Chance = ";
		ms += patternAmount;
		ms += "%		default is 20%";
		optiontext->SetMessage(ms);
	}
	if (coloring)
	{
		std::string ms = "";
		ms += "player color: ";
		ms += playerColor;
		ms += "    spike color: ";
		ms += spikeColor;
		ms += "    patter color: ";
		ms += patternColor;
		optiontext->SetMessage(ms);
	}


	if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(335))
	{
		ReturnButtons();
	}
}
void OptionScene::ReturnButtons()
{
	first = true;
	deciding = false;
	speed = false;
	timing = false;
	pattern = false;
	coloring = false;

	for (Button* b : buttons)
	{
		b->position.x += SCRWIDTH;
	}
	optiontext->SetMessage("");
}

void OptionScene::CreateColorButtons()
{
	for (int i = SCRWIDTH / 2 - 270; i <= SCRWIDTH / 2 + 270; i += 270)
	{
		for (int j = 0; j < colors.size(); j++)
		{
			Button* b = new Button(colors[j], Vector2(i, j * 55 + 80));
			b->scale = 0.8f;
			int collumn = i / 200;
			b->SetMethod(std::bind(&OptionScene::SetColor, this, collumn, colors[j]));
			colorButtons.push_back(b);
			AddObject(b);
		}
	}

	Button* back = new Button("back", Vector2(SCRWIDTH / 2, SCRHEIGHT - 50));
	back->SetMethod(std::bind(&OptionScene::DeleteColorButtons, this));
	colorButtons.push_back(back);
	AddObject(back);
}

void OptionScene::SetColor(int collumn, std::string colorToSet)
{
	switch (collumn)
	{
	case 0:
		playerColor = colorToSet;
		break;
	case 2:
		spikeColor = colorToSet;
		break;
	case 3:
		patternColor = colorToSet;
		break;
	}
}

void OptionScene::DeleteColorButtons()
{
	for (int i = colorButtons.size() - 1; i >= 0; i--)
	{
		DeleteObject(colorButtons[i]);
	}
	ReturnButtons();
}


void OptionScene::CloseOptions()
{
	activescene = previous;
}