#include "Game.h"
#include <raylib.h>
#include "Ship.h"
#include "Invaders.h"
#include "MainMenu.h"
#include <iostream>
#include <string>

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
        DrawText(("Level " + std::to_string(level)).c_str(), 10, 10, 40, WHITE);

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
        DrawText(("Level " + std::to_string(level)).c_str(), 10, 10, 40, WHITE);
        break;

    case GameState::GoBackToMainMenu:
        m_Menu->Draw();
        m_Menu->UpDate();
        break;

    case GameState::TransitionToPlaying:
        break;
    case  GameState::YouLose:
        DrawText("Your Dead!", 200, 100, 50, YELLOW);
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
                    Rectangle bulletRect = { bullet.position.x, bullet.position.y, bullet.width, bullet.height };
                    Rectangle invaderRect = { (float)invader.position.x, (float)invader.position.y, (float)invader.width, (float)invader.height };
                    Rectangle shiprRect = { (float)ship->position.x ,(float)ship->position.y, (float)ship->width, (float)ship->height };

                    if (CheckCollisionRecs(bulletRect, invaderRect))
                    {
                        bullet.SetInActive();
                        invader.setInActive();
                        invader.SpawnSmallCubes(10, 5);
                        allInvadersDefeated = true;
                         
                        

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

                    if (CheckCollisionRecs(invaderRect,shiprRect))
                    {
                        state = GameState::YouLose;
                        ship->getInActive();
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
            invader.speed = 5;
        }
    }

    if (level == 3)
    {
        for (auto& invader : invaders)
        {
           invader.SetInvaderHealth(3);
            invader.speed = 7;
        }
               
    }
}

void Game::CheckLevel()
{
    std::cout << "All invaders defeated!\n";
    level++;
    state = GameState::LevelTransition;

}

void Game::Update()
    {
        
    switch (state)
    {
    case GameState::Menu:
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
               
            }
            m_Menu->ResetPlayerSelection();
        }   
        break;

    case GameState::Playing:
        if (IsKeyPressed(KEY_SPACE))
        {
            bullets.push_back(Bullet(ship->position.x + ship->width / 2 - 2, ship->position.y, 5, 10, WHITE));
        }

        for (auto& bullet : bullets)
        {
            bullet.Move();
        }

        for (auto& invader : invaders)
        {
            invader.Move();
        }

        HandleCollisions(bullets, invaders);
        ship->Move();
        break;

    default:
        break;
    }
}
