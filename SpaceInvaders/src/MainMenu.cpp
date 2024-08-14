#include "MainMenu.h"
#include "raylib.h"
#include "Game.h"

MainMenu::MainMenu()
    :selectedItem(Selected::One)
    , screenHeight(100)
    , screenWidth(100)
    ,Playerselected(false)
    ,textPositionX(4)
    ,textPositionY(5)
    ,startGameTextPositionY(4)
    ,exitGameTextPositionY(4)
    ,textSize(40)
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
        DrawText("Space Invaders", screenWidth / textPositionX, screenHeight / textPositionY, textSize, BLUE);
        DrawText("1. Start Game", screenWidth  / textPositionX, screenHeight / startGameTextPositionY  + textSize, 20, selectedItem ==Selected::One ? RED : DARKGRAY);
        DrawText("2. Exit", screenWidth  / textPositionX, screenHeight /exitGameTextPositionY + 80, 20, selectedItem == 2 ? RED : DARKGRAY);
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
        if (selectedItem > Selected::Two)
        {
            selectedItem = Selected::Zero;
        }
        if (selectedItem < Selected::Zero)
        {
            selectedItem = Selected::Two;
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
