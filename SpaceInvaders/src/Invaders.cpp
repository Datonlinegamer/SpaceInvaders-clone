#include "Invaders.h"

Invader::Invader(float startX, float startY, int w, int h, Color c):
    movingRight{ false }, speed{3.0f}
{
    position = { startX, startY };
    width = w;
    height = h;
    color = c;
    active = true;
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
        DrawRectangle(position.x, position.y, width, height, color);
    }
}