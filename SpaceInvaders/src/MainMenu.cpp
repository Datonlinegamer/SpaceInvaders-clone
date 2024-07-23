#include "MainMenu.h"
#include "raylib.h"
#include "Game.h"

MainMenu::MainMenu(int width, int height)
    : screenWidth(width)
    , screenHeight(height)
    , currentScreen(Title)
    , selectedItem(0)
{
 
}

bool MainMenu::ShouldExit()
{
    return currentScreen ==Quit;
}

void MainMenu::Draw()
{
  
    ClearBackground(RAYWHITE);

    if (currentScreen == Title)
    {
        DrawText("Space Invaders", screenWidth / 2- MeasureText("Space Invaders", 20), screenHeight / 4, 40, DARKGRAY);
        DrawText("Start Game", screenWidth / 2 - MeasureText("Start Game", 20) / 2, screenHeight / 2 - 30, 20, selectedItem == 0 ? RED : DARKGRAY);
        DrawText("Exit", screenWidth / 2 - MeasureText("Exit", 20) / 2, screenHeight / 2 + 30, 20, selectedItem == 2 ? RED : DARKGRAY);
    }
    else if (currentScreen == startGame)
    {
        DrawText("Gameplay Screen", screenWidth / 2 - MeasureText("Gameplay Screen", 20) / 2, screenHeight / 2, 20, DARKGRAY);
     
        

         Level.Draw();
        
    }

}
void MainMenu:: SetSize(int width, int height)
{
    screenHeight = height;
    screenWidth = width;
}
bool MainMenu::WindowShouldClose()
{
    return ::WindowShouldClose();
}

void MainMenu::UpDate()
{
    if (currentScreen ==Title)
    {
        if (IsKeyPressed(KEY_DOWN))
        {
            selectedItem++;
        }

        if (IsKeyPressed(KEY_UP))
        {
            selectedItem--;
        }
        if (selectedItem > 2)
        {
            selectedItem = 0;
        }
        if (selectedItem < 0)
        {
            selectedItem = 2;
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            switch (selectedItem)
            {
            case 0: currentScreen = startGame; break;
            case 1: break; 
            case 2: currentScreen = Quit; break;
            }
        }
    }
}
