#include "MainMenu.h"
#include "raylib.h"


MainMenu::MainMenu()
    :selectedItem(Selected::One)
    ,controlSelection(Controls::controls)
    , screenHeight(100)
    , screenWidth(100)
    ,Playerselected(false)
    ,textPositionX(4)
    ,textPositionY(6)
    ,startGameTextPositionY(5)
    ,exitGameTextPositionY(4)
    ,textSize(40)
    ,inControlMenu(false)
    
{
}
MainMenu::MainMenu(int width, int height)
    : screenWidth(width)
    , screenHeight(height)
    , selectedItem(1)
    ,controlSelection(0)
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
            DrawText("2. Controls", screenWidth  / textPositionX, screenHeight / 4  + textSize, 20, selectedItem == Selected::Two? RED : DARKGRAY);
            DrawText("3. Exit", screenWidth  / textPositionX, screenHeight /exitGameTextPositionY + 80, 20, selectedItem == Selected::Three ? RED : DARKGRAY);


        
        
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
void MainMenu::DrawPlayerControls()
{
         ClearBackground(BLACK);
          
    DrawText("\nBack", 10, 70, 40, controlSelection == Controls::controls ? RED : DARKGRAY);
    DrawText("Press Space to shoot: ", 2, 0, 40, BLUE); 
    DrawText("\nPress wasd to move: ", 1, 30, 40, BLUE);
        
}

void MainMenu::UpDate()
{
    //if (currentScreen == GameMenu::Title)  // Uncommented this condition
   // {
    if (IsKeyPressed(KEY_DOWN))
    {
        selectedItem++;
    }

    if (IsKeyPressed(KEY_UP))
    {
        selectedItem--;
    }

  
    if (selectedItem > Selected::Three)
    {
        selectedItem = Selected::Two;  
    }

    
  


    if (IsKeyPressed(KEY_ENTER))
    {
        Playerselected = true;
        if (controlSelection )
        {
            inControlMenu = true;

        }
       
       
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

   