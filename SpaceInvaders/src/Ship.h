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
    keyinput GetPressedKey();
    Ship(float startX, float startY, int w, int h, Color c);
    void Move() override;
    void Draw() override;
    bool getActive();
    bool getInActive();
private:
  bool active;
  bool inActive;


};