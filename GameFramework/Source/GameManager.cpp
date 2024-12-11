#include "../include/HeaderLib.h"

namespace MichGF
{
    CGameManager& CGameManager::getInstance()
    {
        static CGameManager instance; // Static Instance marking as a Singleton we only use and have 1 game manager
        return instance;
    }

    void CGameManager::vRun()
    {
    }

    CGameManager::CGameManager() : m_rwWindow(sf::VideoMode(800, 600), "PacMan"), m_pCurrentScene(nullptr), m_pCurrentState(nullptr)
    {
    }

    void CGameManager::vInit()
    {
    }

    void CGameManager::vHandleInput()
    {
    }

    void CGameManager::vUpdate(float fDeltaTime)
    {
    }

    void CGameManager::vDraw()
    {
    }

}