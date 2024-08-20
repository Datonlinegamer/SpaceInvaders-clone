#pragma once

#include "raylib.h"
#include "SpaceShipBase.h"
#include <vector>
class Game;
class Invader 
{
public:
    Vector2 position;
    int width;
    int height;
    Color color;
    
    bool movingRight;
    float speed;
    Invader(int startX,int startY, int w, int h, Color c);
    bool getActive();
    void setInActive();
    void Move();
    void Draw();
    void SpawnSmallCubes(float duration, int cubeCount);
    int GetHealth() { return health ; }
    int SetInvaderHealth(int health);
private:
    bool active;
    int health;
  //  Game* l;
    struct SmallCube 
    {
        Vector2 position;
        float size;
        Color color;
    };

    std::vector<SmallCube> cubes;
};
