#pragma once
#include <raylib.h>
class SpaceShipBase
{
public:
    SpaceShipBase() {};
    ~SpaceShipBase() {};
    Vector2 position;
    int width;
    int height;
    Color color;

    SpaceShipBase(float startX, float startY, int w, int h, Color c);
    virtual void Move() = 0;
    virtual void Draw() = 0;
};