#pragma once
class SpaceShip;
#include "Game.h"
#include "SpaceShipBase.h"

class GameSetUp 
{
public:
	void Run();
	bool Runing;
private:
	Game ThisGame;
};