#include "DebugHelper.h"
#include <iostream>

void DebugHelper::IncreaseInvadersSpeed(Invader& invader)
{
	DrawText("Debugger: ON " , 400, 10, 20, RED);
	invader.SetSpeed(10);
}

void DebugHelper::decreaseInvadersSpeed(Invader& invader)
{
	DrawText("Debugger: OFF " , 400, 10, 20, RED);
	invader.SetSpeed(3.0f);
}
