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
        // Display correct level
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
    case GoBackToMainMenu:
        m_Menu->Draw();
        m_Menu->UpDate();
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
                    Rectangle invaderRect = { invader.position.x, invader.position.y, invader.width, invader.height };

                    if (CheckCollisionRecs(bulletRect, invaderRect))
                    {
                        bullet.SetInActive();
                        invader.setInActive();

                        allInvadersDefeated = true; 

                        for (auto& inv : invaders)
                        {
                            if (inv.getActive())
                            {
                                allInvadersDefeated = false; 
                                break;
                            }
                        }

                        // Check the flag after the loop
                        if (allInvadersDefeated)
                        {
                            if (level >= 3)  // End the game after level 3
                            {
                                state = GameState::GameOver;  // Transition to the GameOver state
                                
                            }
                            else
                            {
                                CheckLevel();

                            }
                        }
                            
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
    invaders.clear(); 

    level = this->level;
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
            invader.speed = 5;
        }
    }

    if (level == 3)
    {
        for (auto& invader : invaders)
        {
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
            if (m_Menu->GetPlayerSelection() == 1)
            {
                state = GameState::Playing;
            }
            if (m_Menu->GetPlayerSelection() == 2)
            {
                state = GameState::PlayerControls;
            }
        }
        break;
    case GameState::LevelTransition:
        
        if (allInvadersDefeated)
        {
            DrawText(("Level " + std::to_string(level) + " Starting...  " ).c_str(), 200, 300, 50, YELLOW);
            DrawText( "Please press enter", 200, 400, 50, YELLOW);

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

            DrawText( "You Won!", 200, 100, 50, YELLOW);
            DrawText( "Press enter to go back to main menu", 100, 300, 30, YELLOW);
            if (IsKeyPressed(KEY_ENTER))
            {
                state = GameState::GoBackToMainMenu;
                //tate = GameState::Menu;
                

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
       
        break;
        
        break;
    case GameState::Exit:
        break;

    default:
        break;
    }

    ship->Move();
}
