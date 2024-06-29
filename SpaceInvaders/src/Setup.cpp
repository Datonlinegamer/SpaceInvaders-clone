#include "SetUp.h"
#include "Game.h"


void GameSetUp::Run()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Space Invaders");

    

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
            ThisGame.Update();
           ThisGame.Draw();

        

        EndDrawing();
    }
   
    CloseWindow();

   
};
