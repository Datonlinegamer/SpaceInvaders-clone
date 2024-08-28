#include "MainMenu.h"
#include "raylib.h"
#include <iostream>
#include "AudioManager.h"


MainMenu::MainMenu()
    :m_SelectedItem(Selected::Zero)
    , m_ScreenHeight(100)
    , m_ScreenWidth(100)
    ,m_Playerselected(false)
    ,m_TextPositionX(4)
    ,m_TextPositionY(6)
    ,m_StartGameTextPositionY(5)
    ,m_ExitGameTextPositionY(4)
    ,m_TextSize(40)
    ,inControlMenu(false)
    ,m_InDeathMenu(false)
    
{
}
MainMenu::MainMenu(int width, int height)
    : m_ScreenWidth(width)
    , m_ScreenHeight(height)
    , m_SelectedItem(0)
    ,m_Playerselected(false)
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
                m_InMainMenu = true;
                DrawText("Space Invaders", m_ScreenWidth / m_TextPositionX, m_ScreenHeight / m_TextPositionY, m_TextSize, BLUE);
                DrawText("1. Start Game", m_ScreenWidth  / m_TextPositionX, m_ScreenHeight / m_StartGameTextPositionY  + m_TextSize, 20, m_SelectedItem ==Selected::Zero ? RED : DARKGRAY);
                DrawText("2. Controls", m_ScreenWidth  / m_TextPositionX, m_ScreenHeight / 4  + m_TextSize, 20, m_SelectedItem == Selected::One? RED : DARKGRAY);
                DrawText("3. Exit", m_ScreenWidth  / m_TextPositionX, m_ScreenHeight /m_ExitGameTextPositionY + 80, 20, m_SelectedItem == Selected::Two ? RED : DARKGRAY);

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
    m_ScreenHeight = height;
    m_ScreenWidth = width;
}

void MainMenu::DrawPlayerControls()
{
         ClearBackground(BLACK);
      m_InMainMenu = false;
    DrawText("\nBack", 10, 70, 40, RED);
    DrawText("Press Space to shoot: ", 2, 0, 40, BLUE); 
    DrawText("\nPress ad to move: ", 1, 30, 40, BLUE);
        
}

void MainMenu::YourDead()
{
    if (m_InDeathMenu== true)
    {
        DrawText("Retry",m_ScreenWidth / m_TextPositionX, m_ScreenHeight / 4 + m_TextSize, 20,m_SelectedItem== death::Retry? RED : DARKGRAY);
        DrawText("Back to main menu",m_ScreenWidth / m_TextPositionX, 250, 20, m_SelectedItem== death::Gobacktomainmenu? RED : DARKGRAY);
    }
    
    
    

    

    
}
void MainMenu::HandleDealthInput()
{
    if (m_SelectedItem< death::Retry)
    {
       m_SelectedItem = death::Gobacktomainmenu;
    }
    else if (m_SelectedItem > death::Gobacktomainmenu)
    {
        m_SelectedItem = death::Retry;
    }

   
    
        if (IsKeyPressed(KEY_DOWN))
        {
            m_SelectedItem =  death::Gobacktomainmenu;
            AudioManager::GetInstance()->menuItem();
        }

        if (IsKeyPressed(KEY_UP))
        {
            AudioManager::GetInstance()->menuItem();
            m_SelectedItem = death::Retry;
        }

    
}

void MainMenu::UpDate()
{
    

    if (IsKeyPressed(KEY_DOWN))
    {
        m_SelectedItem++;
        AudioManager::GetInstance()->menuItem();
    }

    if (IsKeyPressed(KEY_UP))
    {
        AudioManager::GetInstance()->menuItem();
        m_SelectedItem--;
    }
        
  
    if (m_SelectedItem > Selected::Three)
    {
        m_SelectedItem = Selected::Two;  
    }
    if (m_SelectedItem > Selected::Two)
    {
        m_SelectedItem = Selected::Three;
    }

    


    if (IsKeyPressed(KEY_ENTER))
    {
        m_Playerselected = true;
        
        if (m_SelectedItem == 1 && !inControlMenu && m_InMainMenu)
        {
           
            inControlMenu = true;
        }

        else if(inControlMenu)
        {
            inControlMenu = false;
        }

        if (m_SelectedItem < Selected::One)
        {
           
            m_InMainMenu =true;
           m_SelectedItem = Selected::Zero;
           m_Playerselected = true;

        }
        if (m_SelectedItem==1 &&m_InDeathMenu ==false)
        {
            m_InDeathMenu = true;
        }
        if (m_SelectedItem ==2)
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

   