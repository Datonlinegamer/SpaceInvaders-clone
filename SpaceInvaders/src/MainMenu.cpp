#include "MainMenu.h"
#include "raylib.h"
#include "Game.h"

MainMenu::MainMenu()
    :selectedItem(1)
    , screenHeight(100)
    , screenWidth(100)
    ,Playerselected(false)
{

}
MainMenu::MainMenu(int width, int height)
    : screenWidth(width)
    , screenHeight(height)
    , selectedItem(1)
    ,Playerselected(false)
{
   
}



void MainMenu::Draw()
{
  
    ClearBackground(BLACK);

    //if (currentScreen == GameMenu::Title)
    {
        DrawText("Space Invaders", screenWidth / 4, screenHeight / 4,  40, BLUE);
        DrawText("1. Start Game", screenWidth  / 4, screenHeight / 4  + 40, 20, selectedItem ==1 ? RED : DARKGRAY);
        DrawText("2. Exit", screenWidth  / 4, screenHeight / 4 + 80, 20, selectedItem == 2 ? RED : DARKGRAY);
    }
    //else if (currentScreen == GameMenu::startGame)
    //{
    //    DrawText("Gameplay Screen", screenWidth  / 2, screenHeight / 2, 20, DARKGRAY);
    // 


    //    //       level.Draw();
    //    
    //}

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
   // if (currentScreen == GameMenu::Title)
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
            Playerselected = true;
          /*  switch (selectedItem)
            {
            case 1:
              currentScreen = GameMenu::startGame;
                break; 
            case 2: currentScreen = GameMenu::Quit;
                break;
                
            default:
                break;
            }*/
        }
    }
}
