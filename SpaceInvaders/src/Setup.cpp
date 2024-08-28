#include "SetUp.h"
#include "Game.h"



void GameSetUp::Run()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Space Invaders");
    InitAudioDevice();
    m_Game.SetWidthAndHeight(screenWidth, screenHeight);
    
   

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        ClearBackground(BLACK);
       
        m_Game.Draw();
     
         m_Game.Update();

        

        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();

   
};
