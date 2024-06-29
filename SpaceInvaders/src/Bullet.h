#pragma once
#include "raylib.h"
#include "SpaceShipBase.h"
class Bullet : SpaceShipBase
{
public:
    Vector2 position;
    int width;
    int height;
    Color color;
    bool active;

    Bullet();
    Bullet(float startX, float startY, int w, int h, Color c);
   virtual void Move();
   virtual void Draw();
};
