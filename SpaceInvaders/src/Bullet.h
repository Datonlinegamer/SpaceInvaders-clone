#pragma once
#include "raylib.h"
#include "SpaceShipBase.h"
class Bullet
{
public:
    Vector2 position;
    int width;
    int height;
    Color color;
    
    bool getActive();
    void SetInActive();
    Bullet();
    Bullet(float startX, float startY, int w, int h, Color c);
    void Move();
    void Draw();

private:
    bool active;
    bool inActive;
};
