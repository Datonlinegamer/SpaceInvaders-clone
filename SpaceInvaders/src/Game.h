#pragma once
#include "SpaceShipBase.h"
#include "raylib.h"
#include <vector>
#include "Bullet.h"
#include "MainMenu.h"
#include "DebugHelper.h"
class Ship;
class Invader;
class MainMenu;
class DebugHelper;
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
//enum DeathScreen
//{
//    Retry=5,
//    Backtomainmeu
//};
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
    DebugHelper* debugger;
    void RestartGame();
    void StartLevel(int level);
    void CheckLevel();  
    bool allInvadersDefeated;
    bool increaseSpeed = false;
    Rectangle shiprRect;
    Rectangle invaderRect;
};

		

