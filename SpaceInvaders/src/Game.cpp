#include "Game.h"
#include <raylib.h>
#include "Ship.h"
#include "Invaders.h"

Game::Game()
{
 ship = new Ship{ 400, 550, 50, 10, BLUE };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            invaders.push_back(Invader(50 + j * 50, 50 + i * 50, 40, 20, RED));
        }
    }
}
Game::~Game()
{
    delete ship;
}
void Game::Draw()
{
    ship->Draw();
    for (auto& bullet : bullets)
    {
        bullet.Draw();
    }

    for (auto& invader : invaders)
    {
        invader.Draw();
    }
}


void HandleCollisions(std::vector<Bullet>& bullets, std::vector<Invader>& invaders) {
    for (auto& bullet : bullets) 
    {
        if (bullet.active) 
        {
            for (auto& invader : invaders) 
            {
                if (invader.active) {
                    Rectangle bulletRect = { bullet.position.x, bullet.position.y, bullet.width, bullet.height };
                    Rectangle invaderRect = { invader.position.x, invader.position.y, invader.width, invader.height };

                
                    DrawRectangleLines(bulletRect.x, bulletRect.y, bulletRect.width, bulletRect.height, RED);
                    DrawRectangleLines(invaderRect.x, invaderRect.y, invaderRect.width, invaderRect.height, BLUE);

                    if (CheckCollisionRecs(bulletRect, invaderRect)) 
                    {
                        bullet.active = false;
                        invader.active = false;
                    }
                }
            }
        }
    }
}





void Game::Update()
{
    ship->Move();

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
}

