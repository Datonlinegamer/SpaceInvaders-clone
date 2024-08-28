#include "SpaceShipBase.h"

SpaceShipBase::SpaceShipBase(float startX, float startY, int w, int h, Color c)
    : m_Width(w)
    ,m_Height(h)
    ,m_Color(c)
{
    m_Position = { startX, startY };
 
}
