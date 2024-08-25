#pragma once
#include "Invaders.h"
class Invader;

class DebugHelper
{
public:
	//DebugHelper();

void IncreaseInvadersSpeed(Invader& invader);
void decreaseInvadersSpeed(Invader& invader);

protected:

	Invader invader;
};