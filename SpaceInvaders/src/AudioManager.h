#pragma once
#include "raylib.h"

class AudioManager
{
	static AudioManager* s_pInstance;
public:
	static  AudioManager* GetInstance();
	static void DestroyInstance();
	AudioManager();
	~AudioManager();
	void ShipShootingSFX();
	void EnemiesHit();
	void Dead();
	void menuItem();

private:
	Sound  m_ShipShootingSFX;
	Sound  m_Hit;
	Sound  m_Dead;
	Sound  m_Menu;
};