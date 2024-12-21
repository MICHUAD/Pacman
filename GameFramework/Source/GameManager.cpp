#include "../include/HeaderLib.h"
#include "../Include/GameManager.h"

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
        // 1. Crear la ventana del juego
        m_rwWindow.create(sf::VideoMode(800, 600), "Pacman");

        // 2. Cargar la fuente
        if (!m_fntFont.loadFromFile("resources/Blox2.ttf")) {
            // Manejar el error de carga de la fuente
            // ...
        }
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