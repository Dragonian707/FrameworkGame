#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "scene.h"
#include "spawner.h"
#include "player.h"
#include "textsprite.h"
#include "pausehud.h"

//class Spawner;

class GameScene : public Scene
{
public:
	/// @brief Constructor
	GameScene();
	/// @brief Destructor
	virtual ~GameScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	Music gametrack;
	Music pausetrack;
	Spawner* spawner;
	Player* player;
	PauseHud* pauseHud;

	std::vector<Spike*> spikes;

	float timer = 0;
	float score = 0;
	bool paused = false;
	int patternchance;

	float spawndelay;

	TextSprite* failtext;
	TextSprite* goToMouse;
	TextSprite* scoretext;

	void ResetScene();
	void PauseGame();
	void OpenOptions();
};

#endif
