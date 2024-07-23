#pragma once
#include "Game.h"

enum GameMenu
{
	Title,
	startGame,
	Quit
};
class MainMenu
{	
public:
	MainMenu(){}
	int screenWidth;
	int screenHeight;
	GameMenu currentScreen;
	int selectedItem;
	MainMenu(int height, int width);
	~MainMenu() {}
	bool ShouldExit();
	Game Level;
	void Draw();
	bool WindowShouldClose();
	void UpDate();
	void SetSize(int width, int height);
};