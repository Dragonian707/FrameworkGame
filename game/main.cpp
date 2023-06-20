#include "raylib.h"

#include "resourcemanager.h"
#include "gamescene.h"
#include "core.h"
#include "settings.h"

int main()
{
	SetConfigFlags(FLAG_WINDOW_UNDECORATED);
	InitWindow(SCRWIDTH, SCRHEIGHT, WINDOWNAME);

	ResourceManager* rs = ResourceManager::Instance();

	GameScene* scene = new GameScene();
	Core core;

    while (!WindowShouldClose()) //while (core.Run(game)) { ; }
    {
		core.Run(scene);
    }

	rs->Cleanup();
    
	CloseWindow();
    
	return 0;
}
