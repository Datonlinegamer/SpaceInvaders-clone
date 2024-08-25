#include "Game.h"
#include <raylib.h>
#include "Ship.h"
#include "Invaders.h"
#include "MainMenu.h"
#include <iostream>
#include <string>
#include "DebugHelper.h"
#include "AudioManager.h"
const int shipWidth = 50;
const int shipHeight = 10;
const float PositionX = 400.0f;
const float PositionY = 550.0f;

Game::Game()
    : level(1),
    allInvadersDefeated(false),
    state(GameState::Menu) // Initialize state to Menu
{
    
    m_Menu = new MainMenu();
    ship = new Ship(PositionX, PositionY, shipWidth, shipHeight, BLUE);
    StartLevel(level);
}

Game::~Game()
{
    delete m_Menu;
    delete ship;
    
}

void Game::Draw()
{
    switch (state)
    {
    case GameState::Menu:
        m_Menu->Draw();
        break;

    case GameState::Playing:
        ship->Draw();
        DrawText(("Level " + std::to_string(level)).c_str(), 10, 10, 40,YELLOW);

        for (auto& bullet : bullets)
        {
            bullet.Draw();
        }

        for (auto& invader : invaders)
        {
            invader.Draw();
        }
        break;

    case GameState::PlayerControls:
        m_Menu->DrawPlayerControls();
        break;

    case GameState::LevelTransition:
        DrawText(("Level " + std::to_string(level)).c_str(), 10, 10, 40, YELLOW);
        break;

    case GameState::GoBackToMainMenu:
        m_Menu->Draw();
        m_Menu->UpDate();
        break;

    case GameState::TransitionToPlaying:
        break;
    case  GameState::YouLose:
        DrawText("Your Dead!", 200, 100, 50, RED);
       m_Menu-> YourDead();
        break;

    case GameState::GameOver:
        DrawText("You Beat the game!", 200, 100, 50, YELLOW);
        DrawText("Press Enter to go back to main menu", 100, 300, 30, YELLOW);

      
        break;

    case GameState::Exit:
        break;

    default:
        break;
    }
}

void Game::HandleCollisions(std::vector<Bullet>& bullets, std::vector<Invader>& invaders)
{
    for (auto& bullet : bullets)
    {
        if (bullet.getActive())
        {
            for (auto& invader : invaders)
            {
                if (invader.getActive())
                {
                    Rectangle bulletRect = {(float) bullet.position.x,(float) bullet.position.y, (float)bullet.width,(float)bullet.height };
                    invaderRect = { (float)invader.position.x, (float)invader.position.y, (float)invader.width, (float)invader.height };
                    shiprRect = { (float)ship->position.x ,(float)ship->position.y, (float)ship->width, (float)ship->height };

                    if (CheckCollisionRecs(bulletRect, invaderRect))
                    {
                        bullet.SetInActive();
                        invader.setInActive();
                        invader.SpawnSmallCubes(10, 5);
                        allInvadersDefeated = true;
                        AudioManager::GetInstance()->EnemiesHit();


                        for (auto& inv : invaders)
                        {
                            if (inv.getActive())
                            {
                                allInvadersDefeated = false;
                                break;
                            }
                        }

                        if (allInvadersDefeated)
                        {
                            if (level >= 3)
                            {
                                state = GameState::GameOver;
                                m_Menu->GameOverScreen();
                                level = 1;
                                for (int i = 0; i < 5; i++)
                                {
                                    for (int j = 0; j < 11; j++)
                                    {
                                        invaders.push_back(Invader(50 + j * 50, 50 + i * 50, 40, 20, RED));
                                    }
                                }


                            }
                            else
                            {
                                CheckLevel();
                            }



                        }
                    }

                    if (CheckCollisionRecs(invaderRect, shiprRect))
                    {

                            state = GameState::YouLose;
                            ship->getInActive();
                            bullet.getActive() == false;
                            invaders.clear();

                        
                        

                    }
                }

                

            }
        }
    }
}

void Game::SetWidthAndHeight(int width, int height)
{
    m_Menu->SetSize(width, height);
}


void Game::StartLevel(int level)
{
   

    this->level = level; 

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            invaders.push_back(Invader(50 + j * 50, 50 + i * 50, 40, 20, RED));
        }
    }

    if (level == 2)
    {
        for (auto& invader : invaders)
        {
             invader.SetInvaderHealth(2);
             invader.SetSpeed(6);
        }
    }

    if (level == 3)
    {
        for (auto& invader : invaders)
        {
           invader.SetInvaderHealth(3);
           invader.SetSpeed(9);
        }
               
    }
}

void Game::CheckLevel()
{
    std::cout << "All invaders defeated!\n";
    level++;
    state = GameState::LevelTransition;

}
void Game:: RestartGame()
{

        level = 1;  
        allInvadersDefeated = false;
        state = GameState::Playing;  

     
        bullets.clear();
        invaders.clear();

      
        delete ship;
        ship = new Ship(PositionX, PositionY, shipWidth, shipHeight, BLUE);

        StartLevel(level);
    
}
void Game::Update()
    {
        
    switch (state)
    {
    case GameState::Menu:
        m_Menu->SetInMainMenu(true);
        m_Menu->UpDate();
        if (m_Menu->GetPlayerSelected())
        {
            if (!m_Menu->GetInControlMenu())
            {
                if (m_Menu->GetPlayerSelection() == 0)
                {
                    state = GameState::Playing;
                   
                }
                
            }
        }
      
    
        break;
    case GameState::LevelTransition:
        if (allInvadersDefeated)
        {
            DrawText(("Level " + std::to_string(level) + " Starting...").c_str(), 200, 300, 50, YELLOW);
            DrawText("Please press Enter", 200, 400, 50, YELLOW);
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            StartLevel(level);
            state = GameState::Playing;
        }
        break;

    case GameState::PlayerControls:
        if (m_Menu->GetControlSeleted() == 0 && IsKeyPressed(KEY_ENTER))
        {
            state = GameState::Menu;
        }
        break;

    case GameState::GameOver:
       

        if (IsKeyPressed(KEY_ENTER))
        {
            if (m_Menu->GetPlayerSelection() == 0)
            {
                state = GameState::Menu;
            }
            else if (m_Menu->GetPlayerSelection() == 1 )
            {
                state = GameState::Playing;
                m_Menu->setInDealthScreen(false);
            }
            m_Menu->ResetPlayerSelection();
        }   
        break;
    case GameState::YouLose:
        state = GameState::YouLose;
        m_Menu->setInDealthScreen(true);
        m_Menu->HandleDealthInput();
        if (IsKeyPressed(KEY_ENTER))
        {
             m_Menu->GetPlayerSelection();

            if (m_Menu->GetPlayerSelection() == 0)
            {
                RestartGame();
            }
            else if (m_Menu->GetPlayerSelection() == 1)
            {
                if (m_Menu->IsInMainMenu())
                {
                    m_Menu->SetInMainMenu(true);
                    state = GameState::GoBackToMainMenu;
                    m_Menu->setInDealthScreen(false);
                    
                }
                        
            }
        }
        break;
    case GameState:: GoBackToMainMenu:               
        if (m_Menu->SetInMainMenu(true))
        {
            if (IsKeyPressed(KEY_UP) )
            {
                m_Menu->GetPlayerSelection() ==0;
            }
            if (IsKeyPressed(KEY_ENTER)&& m_Menu->GetPlayerSelection() ==0)
            {
                RestartGame();
            }
        }
 
      
        break;

    case GameState::Playing:
        if (!CheckCollisionRecs(invaderRect, shiprRect) )
        {
            if (IsKeyPressed(KEY_SPACE))
            {
            bullets.push_back(Bullet(ship->position.x + ship->width / 2 - 2, ship->position.y, 5, 10, WHITE));
            AudioManager::GetInstance()->ShipShootingSFX();

            }
        }

        for (auto& bullet : bullets)
        {
            bullet.Move();
        }

        for (auto& invader : invaders)
        {
            invader.Move();
        }
      
        //Debug menu
      /*     
        if (IsKeyPressed(KEY_F6)) 
        {
           
            increaseSpeed = !increaseSpeed;

          
        }

        if (increaseSpeed)
        {
            for (auto& invader : invaders)
            {
                
                debugger->IncreaseInvadersSpeed(invader);
            }
        }
        else
        {
            for (auto& invader : invaders)
            {
               
                debugger->decreaseInvadersSpeed(invader);  
            }
        }*/
        //Debug menu
            
       
        HandleCollisions(bullets, invaders);
        ship->Move();
        break;

    default:
        break;
    }
}
