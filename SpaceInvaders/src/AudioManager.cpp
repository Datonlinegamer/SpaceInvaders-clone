#include "AudioManager.h"
#include "raylib.h"


AudioManager* AudioManager::s_pInstance = nullptr;


AudioManager* AudioManager::GetInstance()
{
    if (s_pInstance == nullptr)
    {
        s_pInstance = new AudioManager();
    }
    return s_pInstance;
}


void AudioManager::DestroyInstance()
{
    delete s_pInstance;
    s_pInstance = nullptr;
}


AudioManager::AudioManager()
{
  
    m_ShipShootingSFX = LoadSound("SFX/Shooting.ogg");
    m_Hit= LoadSound("SFX/Hit.ogg");
   m_Dead= LoadSound("SFX/Dead.ogg");
   m_Menu = LoadSound("SFX/menustuff.ogg");
}


AudioManager::~AudioManager()
{   
    
    UnloadSound(m_ShipShootingSFX);
    UnloadSound(m_Hit);
    UnloadSound(m_Dead);
    UnloadSound(m_Menu);

}

// Play the ship shooting sound effect
void AudioManager::ShipShootingSFX()
{
    PlaySound(m_ShipShootingSFX);
}

void AudioManager::EnemiesHit()
{
    PlaySound(m_Hit);
}

void AudioManager::Dead()
{
    PlaySound(m_Dead);
}

void AudioManager::menuIten()
{
    PlaySound(m_Menu);
}
