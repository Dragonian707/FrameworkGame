#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "scene.h"
#include "spawner.h"
#include "player.h"
#include "textsprite.h"

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
	Music testTrack;
	Spawner* spawner;
	Player* player;

	std::vector<Spike*> spikes;

	float timer = 0;

	TextSprite* failtext;

	void ResetScene();
};

#endif
