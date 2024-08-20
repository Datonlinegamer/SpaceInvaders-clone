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
    LevelTransition,
    PlayerControls,
    GameOver,
    GoBackToMainMenu,
    TransitionToPlaying,
    YouLose,
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
    Invader* invader;

    Game();
    ~Game();
    void Update();
    void Draw();
    void HandleCollisions(std::vector<Bullet>& bullets, std::vector<Invader>& invaders);

    int level;
    void SetWidthAndHeight(int width, int height);
private:
    void StartLevel(int level);
    void CheckLevel();  
    bool allInvadersDefeated;
  
};

		

