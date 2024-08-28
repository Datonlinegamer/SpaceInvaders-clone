#pragma once
#include <raylib.h>
class SpaceShipBase
{
public:
    SpaceShipBase() {};
    ~SpaceShipBase() {};
    Vector2 m_Position;
    int m_Width;
    int m_Height;
    Color m_Color;

    SpaceShipBase(float startX, float startY, int w, int h, Color c);
    virtual void ShipMovment() = 0;
    virtual void Draw() = 0;
};