#include "Ship.h"



Ship::Ship(float startX, float startY, int w, int h, Color c)
	: SpaceShipBase(startX, startY, w, h, c)
{

}

keyinput Ship::GetPressedKey()
{
    if (IsKeyDown(KEY_A))
    {
        return keyright;
    }
    if (IsKeyDown(KEY_D))
    {
        return keyleft;
    } 
    return key;
}

void Ship::Move()
{
    switch (GetPressedKey())
    {
    case keyright:
        position.x -= 5.0f;
        break;
    case keyleft:
        position.x += 5.0f;
        break;
    case key :
        // No movement
        break;
    }

    // Ensure the player stays within the screen bounds
    if (position.x < 0) position.x = 0;
    if (position.x > GetScreenWidth() - width) position.x = GetScreenWidth() - width;

    
}

void Ship::Draw()
{
    DrawRectangle(position.x, position.y, width, height, color);
}
