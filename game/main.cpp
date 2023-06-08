#include "raylib.h"

#include "resourcemanager.h"
#include "testscene.h"
#include "core.h"
#include "settings.h"

int main()
{
	//eventual outcome
	//Game game = new Game();
	//game.Play();

    InitWindow(SCRWIDTH, SCRHEIGHT, WINDOWNAME);

	ResourceManager* rs = ResourceManager::Instance();

	TestScene* scene = new TestScene();
	Core core;

    while (!WindowShouldClose()) //while (core.Run(game)) { ; }
    {
		core.Run(scene);

		//--------------Text drawing-----------------------------------//
        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(rs->GetFont(), text, 30, 1);
		Vector2 pos = Vector2(SCRWIDTH / 2 - text_size.x / 2, text_size.y + 10);
		DrawTextEx(rs->GetFont(), text, pos, 30, 1, WHITE);
		//--------------end of text drawing----------------------------//

		//std::cout << text_size.x << "     " << text_size.y << std::endl;
    }

	rs->Cleanup();
    
	CloseWindow();
    
	return 0;
}
