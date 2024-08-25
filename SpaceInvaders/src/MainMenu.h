#pragma once
#include "Game.h"
enum death
{
	Retry = 0,
	Gobacktomainmenu =1
};
enum Selected
{
	Zero=0,
	One =1,
	Two =2,
	Three =3,
	four =4,
	five,
	six
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
	int GetPlayerSelection()  { return selectedItem; }
	int SetPlayerSelection() { return selectedItem; }
	void SetSize(int width, int height);
	void DrawPlayerControls();
	bool GetInControlMenu() { return inControlMenu; }
	int GetControlSeleted() { return controlSelection; }
	bool GameOverScreen() { return gameOverSceen = true; }
	void  ResetPlayerSelection() { Playerselected = false; }
	void  ResetPlayerSelectionFromDealthScreen() { Playerselected = true; }
	bool  SetInMainMenu(bool menu) { return inMainMenu; }
	bool getInDeathScreen() { return inDeathMenu; }
	bool setInDealthScreen(bool death) { return inDeathMenu = death; }
	void HandleDealthInput();
	bool IsInMainMenu() { return inMainMenu; }
	void YourDead();
	int textPositionX;
	int textPositionY;
	int textSize;
	int exitGameTextPositionY;
	int deathitem;
	bool Playerselected;
private:
	bool inDeathMenu;
	bool inMainMenu;
	int controlSelection;
	bool inControlMenu;
	int selectedItem;
	int startGameTextPositionY;
	bool gameOverSceen;
	
	
};