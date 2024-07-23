#include "SpaceShipBase.h"

SpaceShipBase::SpaceShipBase(float startX, float startY, int w, int h, Color c)
    : width(w)
    ,height(h)
    ,color(c)
{
    position = { startX, startY };
 
}
