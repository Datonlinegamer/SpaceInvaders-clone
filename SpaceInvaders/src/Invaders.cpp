#include "Invaders.h"

Invader::Invader(int startX, int startY, int w, int h, Color c)
    :movingRight(false) 
    ,speed(3.0f)
    ,active(true)
    ,width(w)
    ,height(h)
    ,color(c)
{
    position = {(float) startX,(float) startY };
    
    
}

bool Invader::getActive()
{
    return active;
}

void Invader::setInActive()
{
     active = false;
}

void Invader::Move() 
{
    if (movingRight)
    {
        position.x += speed;
        if (position.x + width >= GetScreenWidth()) 
        {
            movingRight = false;
            position.y += height; 
        }
    }
    else
    {
        position.x -= speed;
        if (position.x <= 0) 
        {
            movingRight = true;
            position.y += height; 
        }
    }
}


void Invader::Draw() 
{
    if (active) 
    {
        DrawRectangle((float)position.x, (float)position.y,(float) width, (float)height, color);
    }
}