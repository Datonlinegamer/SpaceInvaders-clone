#include "Invaders.h"
#include "Game.h"

Invader::Invader(int startX, int startY, int w, int h, Color c)
    :movingRight(false)
    , speed(3.0f)
    , active(true)
    , width(w)
    , height(h)
    , color(c)
    , health(1)
    
{
    position = {(float) startX,(float) startY };
      
   
}

bool Invader::getActive()
{
    return active;
}

void Invader::setInActive()
{
    if (--health <= 0)  // Decrease health and check if it should be inactive
    {
        active = false;
    }
     
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
  void Invader::SpawnSmallCubes(float duration, int cubeCount) {
    float spawnTime = 0.0f;
    float elapsedTime = 0.0f;
    cubes.clear(); 

    
    for (int i = 0; i < cubeCount; i++) 
    {
        SmallCube cube;
        cube.position = { (float)GetRandomValue(position.x, position.y), (float)GetRandomValue(position.x, position.y) };
        cube.size = 10.0f; 
        cube.color = color;

        cubes.push_back(cube);
    }
    for (auto& cube : cubes)
    {
        DrawRectangle(cube.position.x, cube.position.y, cube.size, cube.size, cube.color);
    }

   
    while (elapsedTime < duration)
    {

        // Update time
        float deltaTime = GetFrameTime();
        elapsedTime += deltaTime;

        // Exit after the duration
        if (elapsedTime >= duration) break;
    }
}

int Invader::SetInvaderHealth(int health)
{
    this->health = health;
    return this->health;
}
