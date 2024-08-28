#pragma once
#include "SpaceShipBase.h"
enum keyinput
{
    key,
    keyleft,
    keyright
};
class Ship : public SpaceShipBase
{
public:
    Ship(float startX, float startY, int w, int h, Color c);
    int Width;
    int Height;
    Rectangle GetRect() const {
        return Rectangle{ m_Position.x, m_Position.y };
    }
    keyinput GetPressedKey();
    void ShipMovment() override;
    void Draw() override;
    bool getActive();
    bool getInActive();
    void SetInactive() { m_Active = false; }

private:
  bool m_Active;
  bool m_InActive;
  float  m_ShipSpeed;


};