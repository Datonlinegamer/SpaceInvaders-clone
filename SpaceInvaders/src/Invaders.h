#pragma once

#include "raylib.h"
#include "SpaceShipBase.h"
class Invader : SpaceShipBase
{
public:
    Vector2 position;
    int width;
    int height;
    Color color;
    bool active;
    bool movingRight;
    float speed;
    Invader(float startX, float startY, int w, int h, Color c);
    void Move() override;
    void Draw() override;
    
};
