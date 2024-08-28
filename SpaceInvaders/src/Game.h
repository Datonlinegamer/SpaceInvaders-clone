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
    YouWon,
    GoBackToMainMenu,
    TransitionToPlaying,
    YouLose,
    Exit
};

class Game
{
public:
    GameState m_State;
    Ship* m_pShip;
    std::vector<Bullet> bullets;
    std::vector<Invader> invaders;
    MainMenu* m_pMenu;
    Invader* m_pInvader;

    Game();
    ~Game();
    void Update();
    void Draw();
    void HandleCollisions(std::vector<Bullet>& bullets, std::vector<Invader>& invaders);
    void HandleCollisionsBetweenInvaderandShip(Ship* ship , std::vector<Invader>& invaders);

    int m_Level;
    void SetWidthAndHeight(int width, int height);
private:
    DebugHelper* m_pDebugger;
    void RestartGame();
    void StartLevel(int level);
    void CheckLevel();  
    bool m_AllInvadersDefeated;
    bool m_IncreaseSpeed = false;
    Rectangle m_ShipRect;
    Rectangle m_InvaderRect;
};

		

