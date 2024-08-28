#include "Invaders.h"
#include "Game.h"
#include "AudioManager.h"

Invader::Invader(int startX, int startY, int w, int h, Color c)
    :m_movingRight(false)
    , m_InvaderSpeed(3.0f)
    , m_Active(true)
    , m_width(w)
    , m_Height(h)
    , m_Color(c)
    , m_Health(1)
    ,m_SpawnTime(0.0f)
    ,m_ElapsedTime(0.0f)
    
{
    m_Position = {(float) startX,(float) startY };
      
   
}



bool Invader::getActive()
{
    return m_Active;
}

void Invader::setInActive()
{
    if (--m_Health <= 0)  
    {
        AudioManager::GetInstance()->Dead();
        m_Active = false;
    }
     
}

void Invader::InvaderMovment() 
{
    if (m_movingRight)
    {
        m_Position.x += m_InvaderSpeed;
        if (m_Position.x + m_width >= GetScreenWidth()) 
        {
            m_movingRight = false;
            m_Position.y += m_Height; 
        }
    }
    else
    {
        m_Position.x -= m_InvaderSpeed;
        if (m_Position.x <= 0) 
        {
            m_movingRight = true;
            m_Position.y += m_Height; 
        }
    }
}


void Invader::Draw() 
{
    if (m_Active) 
    {
        DrawRectangle((float)m_Position.x, (float)m_Position.y,(float) m_width, (float)m_Height, m_Color);
    }
  
}
  void Invader::SpawnSmallCubes(float duration, int cubeCount) 
  {
    
    cubes.clear(); 

    
    for (int i = 0; i < cubeCount; i++) 
    {
        SmallCube cube;
        cube.m_Position = { (float)GetRandomValue(m_Position.x, m_Position.y), (float)GetRandomValue(m_Position.x, m_Position.y) };
        cube.m_Size = 10.0f; 
        cube.m_Color = m_Color;

        cubes.push_back(cube);
    }
    for (auto& cube : cubes)
    {
        DrawRectangle(cube.m_Position.x, cube.m_Position.y, cube.m_Size, cube.m_Size, cube.m_Color);
    }

   
    while (m_ElapsedTime < duration)
    {

       
        float deltaTime = GetFrameTime();
        m_ElapsedTime += deltaTime;

        
        if (m_ElapsedTime >= duration) break;
    }
}

int Invader::SetInvaderHealth(int health)
{
    this->m_Health = health;
    return this->m_Health;
}
