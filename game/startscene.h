#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "scene.h"

class StartScene : public Scene
{
public:
	/// @brief Constructor
	StartScene();
	/// @brief Destructor
	virtual ~StartScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:

};

#endif /* SCENE00_H */
