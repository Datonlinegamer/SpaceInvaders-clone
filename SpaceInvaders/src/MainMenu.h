#pragma once
#include "Game.h"
enum Controls
{
	controls = 0
};
enum Selected
{
	Zero=0,
	One =1,
	Two =2,
	Three =3,
	four =4
};
enum GameMenu
{
	Title,
	startGame,
	Controls,
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
	void DrawPlayerControls();
	bool GetInControlMenu() { return inControlMenu; }
	int GetControlSeleted() { return controlSelection; }
	
private:
	
	int controlSelection;
	bool inControlMenu;
	bool Playerselected;
	int selectedItem;
	int textPositionX;
	int textPositionY;
	int startGameTextPositionY;
	int exitGameTextPositionY;
	int textSize;
	
	
};