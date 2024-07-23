#include "Bullet.h"



bool Bullet::getActive()
{
    return active;
}

void Bullet::SetInActive()
{
    active = false;
}

Bullet::Bullet(float startX, float startY, int w, int h, Color c)
    :active(true)
    ,width(w)
    ,height(h)
    ,color(c)
{
    position = { startX, startY };
    
    
}

void Bullet::Move() 
{
    if (active) 
    {
        position.y -= 10.0f;
        if (position.y < 0) 
        {
            active = false;
        }
    }
}

void Bullet::Draw() 
{
    if (active) 
    {
        DrawRectangle(position.x, position.y, width, height, color);
    }
}
