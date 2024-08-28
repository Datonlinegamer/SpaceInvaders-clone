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
	int m_ScreenWidth;
	int m_ScreenHeight;
	MainMenu(int width, int height);
	~MainMenu() {}
	void Draw();
	void UpDate();
	bool GetPlayerSelected() const{ return m_Playerselected; }
	int GetPlayerSelection()  { return m_SelectedItem; }
	int SetPlayerSelection() { return m_SelectedItem; }
	void SetSize(int width, int height);
	void DrawPlayerControls();
	bool GetInControlMenu() { return inControlMenu; }
	int GetControlSeleted() { return m_ControlSelection; }
	bool GameOverScreen() { return m_GameOverSceen = true; }
	void  ResetPlayerSelection() { m_Playerselected = false; }
	void  ResetPlayerSelectionFromDealthScreen() { m_Playerselected = true; }
	bool  SetInMainMenu(bool menu) { return m_InMainMenu; }
	bool getInDeathScreen() { return m_InDeathMenu; }
	bool setInDealthScreen(bool death) { return m_InDeathMenu = death; }
	void HandleDealthInput();
	bool IsInMainMenu() { return m_InMainMenu; }
	void YourDead();
	int m_TextPositionX;
	int m_TextPositionY;
	int m_TextSize;
	int m_ExitGameTextPositionY;
private:
	bool m_Playerselected;
	bool m_InDeathMenu;
	bool m_InMainMenu;
	int m_ControlSelection;
	bool inControlMenu;
	int m_SelectedItem;
	int m_StartGameTextPositionY;
	bool m_GameOverSceen;
	
	
};