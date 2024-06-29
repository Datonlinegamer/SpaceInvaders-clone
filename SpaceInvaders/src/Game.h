#pragma once
#include "SpaceShipBase.h"
#include "raylib.h"
#include <vector>
#include "Bullet.h"
class Ship;
class Invader;
class Game  
{
public:
    Ship* ship;
    std::vector<Bullet> bullets;
    std::vector<Invader> invaders;

    Game();
    ~Game();
    void Update();
    void Draw();
    void HandleCollision(std::vector<Bullet>& bullets, std::vector<Invader>& invaders);
};

		

