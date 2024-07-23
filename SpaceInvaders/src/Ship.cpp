#include "Ship.h"



Ship::Ship(float startX, float startY, int w, int h, Color c)
    : SpaceShipBase(startX, startY, w, h, c), active( true )
{

}

keyinput Ship::GetPressedKey()
{
    if (IsKeyDown(KEY_A))
    {
        return keyleft;
    }
    if (IsKeyDown(KEY_D))
    {
        return keyright;
    } 
    return key;
}

void Ship::Move()
{
    switch (GetPressedKey())
    {
    case keyleft:
        position.x -= 5.0f;
        break;
    case keyright:
        position.x += 5.0f;
        break;
    case key :
    
        break;
    }


    if (position.x < 0)
    {
        position.x = 0;
    }
    if (position.x > GetScreenWidth() - width)
    {
     position.x = GetScreenWidth() - width;
    }

    
}

void Ship::Draw()
{
    if (getActive())
    {
        DrawRectangle(position.x, position.y, width, height, color);
    }
}

bool Ship::getActive()
{
    return active;
}

bool Ship::getInActive()
{
    return active = false;
}
