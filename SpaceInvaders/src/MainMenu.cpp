#include "MainMenu.h"
#include "raylib.h"
#include <iostream>
#include "AudioManager.h"


MainMenu::MainMenu()
    :selectedItem(Selected::Zero)
    ,deathitem(death::Retry)
    , screenHeight(100)
    , screenWidth(100)
    ,Playerselected(false)
    ,textPositionX(4)
    ,textPositionY(6)
    ,startGameTextPositionY(5)
    ,exitGameTextPositionY(4)
    ,textSize(40)
    ,inControlMenu(false)
    ,inDeathMenu(false)
    
{
}
MainMenu::MainMenu(int width, int height)
    : screenWidth(width)
    , screenHeight(height)
    , selectedItem(0)
   // ,controlSelection(0)
    ,Playerselected(false)
{
   
}



void MainMenu::Draw()
{
  
    ClearBackground(BLACK);

    //if (currentScreen == GameMenu::Title)
    {
        
      
            

            if (inControlMenu == true)
            {
                DrawPlayerControls();
            }
            else
            {
                inMainMenu = true;
                DrawText("Space Invaders", screenWidth / textPositionX, screenHeight / textPositionY, textSize, BLUE);
                DrawText("1. Start Game", screenWidth  / textPositionX, screenHeight / startGameTextPositionY  + textSize, 20, selectedItem ==Selected::Zero ? RED : DARKGRAY);
                DrawText("2. Controls", screenWidth  / textPositionX, screenHeight / 4  + textSize, 20, selectedItem == Selected::One? RED : DARKGRAY);
                DrawText("3. Exit", screenWidth  / textPositionX, screenHeight /exitGameTextPositionY + 80, 20, selectedItem == Selected::Two ? RED : DARKGRAY);

            }
           
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

void MainMenu::DrawPlayerControls()
{
         ClearBackground(BLACK);
      inMainMenu = false;
    DrawText("\nBack", 10, 70, 40, RED);
    DrawText("Press Space to shoot: ", 2, 0, 40, BLUE); 
    DrawText("\nPress ad to move: ", 1, 30, 40, BLUE);
        
}

void MainMenu::YourDead()
{
    if (inDeathMenu== true)
    {
    DrawText("Retry",screenWidth / textPositionX, screenHeight / 4 + textSize, 20,selectedItem== death::Retry? RED : DARKGRAY);
    DrawText("Back to main menu",screenWidth / textPositionX, 250, 20, selectedItem== death::Gobacktomainmenu? RED : DARKGRAY);
    }
    
    
    

    

    
}
void MainMenu::HandleDealthInput()
{
    if (selectedItem< death::Retry)
    {
       selectedItem = death::Gobacktomainmenu;
    }
    else if (selectedItem > death::Gobacktomainmenu)
    {
        selectedItem = death::Retry;
    }

   
    
        if (IsKeyPressed(KEY_DOWN))
        {
            selectedItem =  death::Gobacktomainmenu;
            AudioManager::GetInstance()->menuIten();
        }

        if (IsKeyPressed(KEY_UP))
        {
            AudioManager::GetInstance()->menuIten();
            selectedItem = death::Retry;
        }

    
}

void MainMenu::UpDate()
{
    

    if (IsKeyPressed(KEY_DOWN))
    {
        selectedItem++;
        AudioManager::GetInstance()->menuIten();
    }

    if (IsKeyPressed(KEY_UP))
    {
        AudioManager::GetInstance()->menuIten();
        selectedItem--;
    }
        
  
    if (selectedItem > Selected::Three)
    {
        selectedItem = Selected::Two;  
    }
    if (selectedItem > Selected::Two)
    {
        selectedItem = Selected::Three;
    }

    


    if (IsKeyPressed(KEY_ENTER))
    {
        Playerselected = true;
        
        if (selectedItem == 1 && !inControlMenu && inMainMenu)
        {
           
            inControlMenu = true;
        }

        else if(inControlMenu)
        {
            inControlMenu = false;
        }

        if (selectedItem < Selected::One)
        {
           
            inMainMenu =true;
           selectedItem = Selected::Zero;
           Playerselected = true;

        }
        if (selectedItem==1 &&inDeathMenu ==false)
        {
            inDeathMenu = true;
        }
        if (selectedItem ==2)
        {
            CloseWindow();
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

   