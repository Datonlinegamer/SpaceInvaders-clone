#pragma once

#include "raylib.h"
#include "SpaceShipBase.h"
#include <vector>

class Invader 
{
public:
    Vector2 m_Position;
    int m_width;
    int m_Height;
    Color m_Color;
    
    bool m_movingRight;
    float m_InvaderSpeed;
    Invader(int startX,int startY, int w, int h, Color c);
    bool getActive();
    void setInActive();
    void InvaderMovment();
    void Draw();
    void SpawnSmallCubes(float duration, int cubeCount);
    int GetHealth() { return m_Health ; }
    int SetInvaderHealth(int health);
    int SetSpeed(float newSpeed) { return m_InvaderSpeed = newSpeed; };
   
private:
    float m_SpawnTime;
    float m_ElapsedTime;
    bool m_Active;
    int m_Health;

    struct SmallCube 
    {
        Vector2 m_Position;
        float m_Size;
        Color m_Color;
    };

    std::vector<SmallCube> cubes;
};
