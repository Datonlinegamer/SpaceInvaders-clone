#pragma once

#include "MainMenu.h"
#include "Game.h"
class GameSetUp 
{
public:
	
	void Run();
	bool m_Runing;
private:
	
	Game m_Game;
};