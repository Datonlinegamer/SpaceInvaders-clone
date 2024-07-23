#pragma once
#include "SpaceShipBase.h"
#include "raylib.h"
#include <vector>
#include "Bullet.h"
#include "MainMenu.h"
class Ship;
class Invader;
class MainMenu;
enum GameState
{
    Menu,
    Playing,
    Exit
};

class Game
{
public:
    GameState state;
    Ship* ship;
    std::vector<Bullet> bullets;
    std::vector<Invader> invaders;
    MainMenu* m_Menu;
    

    Game();
    ~Game();
    void Update();
    void Draw();
    void HandleCollisions(std::vector<Bullet>& bullets, std::vector<Invader>& invaders);

    void SetWidthAndHeight(int width, int height);
private:
 
   
 
  
};

		

