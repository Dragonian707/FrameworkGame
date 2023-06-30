#ifndef SPAWNER_H
#define SPAWNER_H

#include "raylib.h"
#include "sprite.h"
//#include "testscene.h"
//#include "scene.h"
#include "spike.h"
#include <vector>

//class TestScene;

class Spawner
{
public:
	/// @brief Constructor
	//Spawner(Scene* s);
	Spawner();
	/// @brief Destructor
	virtual ~Spawner();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	//virtual void update(float deltaTime);

	//Spike* Spawn(bool pattern);
	std::vector<Spike*> Spawn(bool pattern);

	Color GetPlayerColor() { return PlayerColor; };
private:
	//virtual void UpdateObject(float deltatime);

	std::vector<Spike*> Pattern(int pattern);
	std::map<std::string, Color> colors{ {"blue", BLUE}, {"Red", RED},  {"Green", GREEN}, {"Yellow", YELLOW}, {"Purple", PURPLE}, {"White", WHITE}, {"Brown", BROWN}, {"Orange",ORANGE}, {"Pink", PINK}, {"Lime", LIME}, {"Violet", VIOLET}, {"Gray", GRAY} };

	Color PlayerColor;
	Color SpikeColor;
	Color PatternColor;

	void ParseColors();

	//Scene* scene;
};

#endif
