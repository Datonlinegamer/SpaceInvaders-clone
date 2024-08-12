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
	MainMenu();
	int screenWidth;
	int screenHeight;
	GameMenu currentScreen;
	MainMenu(int width, int height);
	~MainMenu() {}
	bool ShouldExit();
	void Draw();
	bool WindowShouldClose();
	void UpDate();
	bool GetPlayerSelected() const{ return Playerselected; }
	int GetPlayerSelection() const { return selectedItem; }
	void SetSize(int width, int height);
private:
	bool Playerselected;
	int selectedItem;
	
};