#include "Bullet.h"

Bullet::Bullet() : active(true) {}

Bullet::Bullet(float startX, float startY, int w, int h, Color c) {
    position = { startX, startY };
    width = w;
    height = h;
    color = c;
    active = true;
}

void Bullet::Move() 
{
    if (active) {
        position.y -= 10.0f;
        if (position.y < 0) {
            active = false;
        }
    }
}

void Bullet::Draw() {
    if (active) 
    {
        DrawRectangle(position.x, position.y, width, height, color);
    }
}
