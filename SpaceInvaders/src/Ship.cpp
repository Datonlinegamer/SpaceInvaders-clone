#include "Ship.h"



Ship::Ship(float startX, float startY, int w, int h, Color c)
    : SpaceShipBase(startX, startY, w, h, c),
    m_Active( true )
    ,m_ShipSpeed(300.0f)
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

void Ship::ShipMovment()
{
    switch (GetPressedKey())
    {
    case keyleft:
        m_Position.x -= m_ShipSpeed *GetFrameTime();
        break;
    case keyright:
        m_Position.x += m_ShipSpeed * GetFrameTime();
        break;
    case key :
    
        break;
    }


    if (m_Position.x < 0)
    {
        m_Position.x = 0;
    }
    if (m_Position.x > GetScreenWidth() - m_Width)
    {
     m_Position.x = GetScreenWidth() - m_Width;
    }

    
}

void Ship::Draw()
{
    if (getActive())
    {
        DrawRectangle(m_Position.x, m_Position.y, m_Width, m_Height, m_Color);
    }
}

bool Ship::getActive()
{
    return m_Active;
}

bool Ship::getInActive()
{
    
    return m_Active  == false;
}
