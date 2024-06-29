#include "SpaceShipBase.h"

SpaceShipBase::SpaceShipBase(float startX, float startY, int w, int h, Color c)
{
    position = { startX, startY };
    width = w;
    height = h;
    color = c;
}
