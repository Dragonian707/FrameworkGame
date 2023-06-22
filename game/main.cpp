#include "raylib.h"

#include "resourcemanager.h"
#include "gamescene.h"
#include "core.h"
#include "settings.h"

#include "scenemanager.h"

int main()
{
	SetConfigFlags(FLAG_WINDOW_UNDECORATED);
	InitWindow(SCRWIDTH, SCRHEIGHT, WINDOWNAME);

	ResourceManager* rs = ResourceManager::Instance();
	SceneManager* s = SceneManager::Instance();
	Core core;

    while (core.running) //while (core.Run(game)) { ; }
    {
		core.Run(s->GetActiveScene());
    }

	rs->Cleanup();
    
	CloseWindow();
    
	return 0;
}
