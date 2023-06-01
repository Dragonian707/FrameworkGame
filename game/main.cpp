#include "raylib.h"

constexpr auto SCREEN_WIDTH  = 800;
constexpr auto SCREEN_HEIGHT = 450;

#include "resourcemanager.h"
#include "object.h"
int main()
{
	//eventual outcome
	//Game game = new Game();
	//game.Play();

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    //SetTargetFPS(60);

	ResourceManager* rs = ResourceManager::Instance();
	//Texture2D texture = rs->GetTexture("assets/test.png");
	//Texture2D texture2 = rs->GetTexture("assets/test.png");

	//todo
	//make scene, maybe even core
	//update scene
	float rot = 0;

	Object* i = new Object("assets/test.png");

    while (!WindowShouldClose()) //while (core.Run(game)) { ; }
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

		i->position = Vector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		i->rotation += 0.01f;
		i->Draw();

		/*
        int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
		
		//---------------draw a texture---------------------------------------------//
		Vector2 pos = Vector2(texture_x, texture_y);
		Rectangle sourceRec = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
		Rectangle destRec = { pos.x + texture.width / 2, pos.y + texture.height / 2, (float)texture.width * 1, (float)texture.height * 1 };
		Vector2 origin = { texture.width / 2, texture.height / 2 };
		DrawTexturePro(texture, sourceRec, destRec, origin, rot, WHITE);
		//---------------end of texture drawing------------------------------------//

		rot += 0.01f;
		DrawTexture(texture2, texture_x+200, texture_y, WHITE);

        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y + 10, 20, BLACK);
		*/
        EndDrawing();
    }

 //   UnloadTexture(texture);
	//UnloadTexture(texture2); //simplify

    CloseWindow();
    return 0;
}
