#include "raylib.h"

#include "resourcemanager.h"
#include "testscene.h"
#include "core.h"
#include "settings.h"

int main()
{
    InitWindow(SCRWIDTH, SCRHEIGHT, WINDOWNAME);

	ResourceManager* rs = ResourceManager::Instance();

	TestScene* scene = new TestScene();
	Core core;

    while (!WindowShouldClose()) //while (core.Run(game)) { ; }
    {
		core.Run(scene);
    }

	rs->Cleanup();
    
	CloseWindow();
    
	return 0;
}
