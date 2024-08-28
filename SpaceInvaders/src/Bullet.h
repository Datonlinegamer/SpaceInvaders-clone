#pragma once
#include "raylib.h"
#include "SpaceShipBase.h"
class Bullet
{
public:
    Vector2 m_Position;
    int m_Width;
    int m_Height;
    Color m_Color;
    
    bool getActive();
    void SetInActive();
    Bullet();
    Bullet(float startX, float startY, int w, int h, Color c);
    void BulletMovment();
    void Draw();

private:
    bool m_Active;
    bool m_InActive;
};
