#pragma once

#include "raylib.h"
#include "SpaceShipBase.h"
class Invader 
{
public:
    Vector2 position;
    int width;
    int height;
    Color color;
    
    bool movingRight;
    float speed;
    Invader(int startX,int startY, int w, int h, Color c);
    bool getActive();
    void setInActive();
    void Move();
    void Draw();
private:
    bool active;

};
