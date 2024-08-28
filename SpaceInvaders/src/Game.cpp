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
    : m_Level(1),
    m_AllInvadersDefeated(false),
    m_State(GameState::Menu) // Initialize state to Menu
{
    m_pMenu = new MainMenu();
    m_pShip = new Ship(PositionX, PositionY, shipWidth, shipHeight, BLUE);
    StartLevel(m_Level);
}

Game::~Game()
{
    delete m_pMenu;
    delete m_pShip;
}

void Game::Draw()
{
    switch (m_State)
    {
    case GameState::Menu:
        m_pMenu->Draw();
        break;

    case GameState::Playing:
        m_pShip->Draw();
        DrawText(("Level " + std::to_string(m_Level)).c_str(), 10, 10, 40, YELLOW);

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
        m_pMenu->DrawPlayerControls();
        break;

    case GameState::LevelTransition:
        DrawText(("Level " + std::to_string(m_Level)).c_str(), 10, 10, 40, YELLOW);
        break;

    case GameState::GoBackToMainMenu:
        m_pMenu->Draw();
        m_pMenu->UpDate();
        break;

    case GameState::TransitionToPlaying:
        break;

    case GameState::YouLose:
        DrawText("You Died!", 200, 100, 50, RED);
        m_pMenu->YourDead();
        break;

    case GameState::YouWon:
        DrawText("You Beat the Game!", 200, 100, 50, YELLOW);
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
    Rectangle bulletRect, invaderRect, shipRect;

    for (auto& bullet : bullets)
    {
        if (bullet.getActive())
        {
            bulletRect = { bullet.m_Position.x, bullet.m_Position.y, (float)bullet.m_Width, (float)bullet.m_Height };

            for (auto& invader : invaders)
            {
                if (invader.getActive())
                {
                    invaderRect = { invader.m_Position.x, invader.m_Position.y, (float) invader.m_width,(float) invader.m_Height };
                    shipRect = { m_pShip->m_Position.x, m_pShip->m_Position.y, (float)m_pShip->m_Width, (float)m_pShip->m_Height };

                    if (CheckCollisionRecs(bulletRect, invaderRect))
                    {
                        bullet.SetInActive();
                        invader.setInActive();
                        invader.SpawnSmallCubes(10, 5);
                        m_AllInvadersDefeated = true;
                        AudioManager::GetInstance()->EnemiesHit();
                        
                        for (auto& inv : invaders)
                        {
                            if (inv.getActive())
                            {
                                m_AllInvadersDefeated = false;
                                break;
                            }
                        }

                        if (m_AllInvadersDefeated)
                        {
                            if (m_Level >= 3)
                            {
                                m_State = GameState::YouWon;
                                m_pMenu->GameOverScreen();
                                m_Level = 1;
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
                }
            }
        }
    }
}

void Game::HandleCollisionsBetweenInvaderandShip(Ship* ship, std::vector<Invader>& invaders)
{
    if (!ship) return;

    Rectangle shipRect = { ship->m_Position.x, ship->m_Position.y, ship->m_Width, ship->m_Height };

    for (auto& invader : invaders)
    {
        Rectangle invaderRect = { invader.m_Position.x, invader.m_Position.y, invader.m_width, invader.m_Height };

        if (CheckCollisionRecs(shipRect, invaderRect))
        {
            m_State = GameState::YouLose;
            ship->SetInactive();
            invaders.clear();
            break;
        }
    }
}

void Game::SetWidthAndHeight(int width, int height)
{
    m_pMenu->SetSize(width, height);
}

void Game::StartLevel(int level)
{
    this->m_Level = level;

    invaders.clear();

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
    m_Level++;
    m_State = GameState::LevelTransition;
}

void Game::RestartGame()
{
    m_Level = 1;
    m_AllInvadersDefeated = false;
    m_State = GameState::Playing;

    bullets.clear();
    invaders.clear();

    delete m_pShip;
    m_pShip = new Ship(PositionX, PositionY, shipWidth, shipHeight, BLUE);

    StartLevel(m_Level);
}

void Game::Update()
{
    switch (m_State)
    {
    case GameState::Menu:
        m_pMenu->SetInMainMenu(true);
        m_pMenu->UpDate();
        if (m_pMenu->GetPlayerSelected())
        {
            if (!m_pMenu->GetInControlMenu())
            {
                if (m_pMenu->GetPlayerSelection() == 0)
                {
                    m_State = GameState::Playing;
                }
            }
        }
        break;

    case GameState::LevelTransition:
        if (m_AllInvadersDefeated)
        {
            DrawText(("Level " + std::to_string(m_Level) + " Starting...").c_str(), 150, 100, 50, YELLOW);
            DrawText("Please press Enter", 150, 200, 50, YELLOW);
        }

        if (IsKeyPressed(KEY_ENTER))
        {
            StartLevel(m_Level);
            m_State = GameState::Playing;
        }
        break;

    case GameState::PlayerControls:
        if (m_pMenu->GetControlSeleted() == 0 && IsKeyPressed(KEY_ENTER))
        {
            m_State = GameState::Menu;
        }
        break;

    case GameState::YouWon:
        if (IsKeyPressed(KEY_ENTER))
        {
            if (m_pMenu->GetPlayerSelection() == 0)
            {
                m_State = GameState::Menu;
            }
            else if (m_pMenu->GetPlayerSelection() == 1)
            {
                m_State = GameState::Playing;
                m_pMenu->setInDealthScreen(false);
            }
            m_pMenu->ResetPlayerSelection();
        }
        break;

    case GameState::YouLose:
        m_pMenu->setInDealthScreen(true);
        m_pMenu->HandleDealthInput();
        if (IsKeyPressed(KEY_ENTER))
        {
            if (m_pMenu->GetPlayerSelection() == 0)
            {
                RestartGame();
            }
            else if (m_pMenu->GetPlayerSelection() == 1)
            {
                if (m_pMenu->IsInMainMenu())
                {
                    m_pMenu->SetInMainMenu(true);
                    m_State = GameState::GoBackToMainMenu;
                    m_pMenu->setInDealthScreen(false);
                }
            }
        }
        break;

    case GameState::GoBackToMainMenu:
        if (m_pMenu->IsInMainMenu())
        {
            if (IsKeyPressed(KEY_UP))
            {
                m_pMenu->SetPlayerSelection() == 0;
            }
            if (IsKeyPressed(KEY_ENTER) && m_pMenu->GetPlayerSelection() == 0)
            {
                RestartGame();
            }
        }
        break;

    case GameState::Playing:
        if (!CheckCollisionRecs(m_InvaderRect, m_ShipRect))
        {
            if (IsKeyPressed(KEY_SPACE))
            {
                bullets.push_back(Bullet(m_pShip->m_Position.x + m_pShip->m_Width / 2 - 2, m_pShip->m_Position.y, 5, 10, WHITE));
                AudioManager::GetInstance()->ShipShootingSFX();
            }
        }

        for (auto& bullet : bullets)
        {
            bullet.BulletMovment();
        }

        for (auto& invader : invaders)
        {
            invader.InvaderMovment();
        }

        HandleCollisionsBetweenInvaderandShip(m_pShip, invaders);
        HandleCollisions(bullets, invaders);
        m_pShip->ShipMovment();
        break;

    default:
        break;
    }
}
