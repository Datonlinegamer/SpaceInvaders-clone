#include "Bullet.h"



bool Bullet::getActive()
{
    return m_Active;
}

void Bullet::SetInActive()
{
    m_Active = false;
}

Bullet::Bullet(float startX, float startY, int w, int h, Color c)
    :m_Active(true)
    ,m_Width(w)
    ,m_Height(h)
    ,m_Color(c)
{
    m_Position = { startX, startY };
    
    
}

void Bullet::BulletMovment() 
{
    if (m_Active) 
    {
        m_Position.y -= 10.0f;
        if (m_Position.y < 0) 
        {
            m_Active = false;
        }
    }
}

void Bullet::Draw() 
{
    if (m_Active) 
    {
        DrawRectangle(m_Position.x, m_Position.y, m_Width, m_Height, m_Color);
    }
}
