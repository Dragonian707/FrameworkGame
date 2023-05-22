#include "raylib.h"

constexpr auto SCREEN_WIDTH  = 800;
constexpr auto SCREEN_HEIGHT = 450;

#include "resourcemanager.h"
int main()
{
	//eventual outcome
	//Game game = new Game();
	//game.Play();

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window title");
    //SetTargetFPS(60);

	ResourceManager* rs = ResourceManager::Instance();
	Texture2D texture = rs->GetTexture(ASSETS_PATH"test.png");
	Texture2D texture2 = rs->GetTexture(ASSETS_PATH"test.png");

	//todo
	//make scene, maybe even core
	//update scene

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        const int texture_x = SCREEN_WIDTH / 2 - texture.width / 2;
        const int texture_y = SCREEN_HEIGHT / 2 - texture.height / 2;
        DrawTexture(texture, texture_x-100, texture_y, WHITE);
		DrawTexture(texture2, texture_x+100, texture_y, WHITE);

        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y + 10, 20, BLACK);

        EndDrawing();
    }

    UnloadTexture(texture);
	UnloadTexture(texture2); //simplify

    CloseWindow();
    return 0;
}
