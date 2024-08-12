#include "Game.h"
#include <raylib.h>
#include "Ship.h"
#include "Invaders.h"
#include "MainMenu.h"

const int shipWidth = 50;
const int shipHeight = 10;
const float PositionX = 400.0f;
const float PositionY = 550.0f;
Game::Game()
{
   m_Menu = new MainMenu();
    //state = GameState::Menu;
 ship = new Ship( PositionX, PositionY, shipWidth, shipHeight, BLUE );

    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 11; j++) 
        {
            invaders.push_back(Invader(50 + j * 50, 50 + i * 50, 40, 20, RED));
        }
    }
}
Game::~Game()
{
    delete m_Menu;
    m_Menu = nullptr;
    delete ship;
    ship = nullptr;
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
        DrawText("Level 1", 0/ 2, 0 / 4, 40, WHITE);
        for (auto& bullet : bullets)
        {
            bullet.Draw();
        }

        for (auto& invader : invaders)
        {
            invader.Draw();
        }
        break;

    case GameState::Exit:
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
                    Rectangle bulletRect = { (float)bullet.position.x,(float) bullet.position.y,(float) bullet.width,(float) bullet.height };
                    Rectangle invaderRect = { (float)invader.position.x,(float) invader.position.y, (float)invader.width,(float) invader.height };




                    if (CheckCollisionRecs(bulletRect, invaderRect))
                    {
                        bullet.SetInActive();
                        invader.setInActive();
                    }

                    if (ship->getActive())
                    {
                        Rectangle shipRec = { (float)ship->position.x,(float)ship->position.y,(float)ship->width, (float)ship->height };

                        if (CheckCollisionRecs(shipRec, invaderRect))
                        {
                            ship->getInActive();
                            if (ship->getInActive())
                            {
                                                   
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
    m_Menu->SetSize(width,height);
}

void Game::Update()
{
    switch (state)
    {
    case GameState::Menu:

       m_Menu->UpDate();
       if (m_Menu->GetPlayerSelected())
       {
           if (m_Menu->GetPlayerSelection() ==1)
           {
             state = GameState::Playing;

           }
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
    case Exit:
        break;
    default:
        break;
    }
    ship->Move();
  
}

