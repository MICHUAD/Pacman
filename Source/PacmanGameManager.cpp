#include "../Include/PacManHeaderLib.h"
#include "../Include/PacmanGameManager.h"
#include "../Include/PacmanGameState.h"
#include <memory>



void CPacmanGameManager::vInit()
{
    // 1. Crear una instancia del estado de juego de Pacman
    std::shared_ptr<CPacmanGameState> pGameState = std::make_shared<CPacmanGameState>(this);
    m_eCurrentGameState = GAMESTATE::GAME;

    // 2. Inicializar el estado de juego
    pGameState->vInit();

    // 3. Asignar el estado de juego al GameManager
    m_pCurrentState = pGameState;
}

void CPacmanGameManager::vHandleInput()
{
    sf::Event event;
    while (m_rwWindow.pollEvent(event))
    {
        // Pasar el evento al estado actual del juego
        if (m_pCurrentState != nullptr) {
            m_pCurrentState->vHandleInput(); // Pasar el evento al estado
        }
    }
}

void CPacmanGameManager::vUpdate(float fDeltaTime)
{
    if (m_pCurrentState != nullptr) {
        m_pCurrentState->vUpdate(fDeltaTime);
    }
}

void CPacmanGameManager::vDraw()
{
	if (m_pCurrentState != nullptr) {
		m_pCurrentState->vDraw(m_rwWindow);
	}
}

void CPacmanGameManager::vRun()
{
    // Llamar al método vInit() de la clase base para inicializar el juego
    vInit();

    // Bucle principal del juego
    while (m_rwWindow.isOpen())
    {
       
        // Calcular el tiempo transcurrido desde el último frame
        sf::Time deltaTime = m_cClock.restart();

        // Obtener el estado actual del juego
        std::shared_ptr<CPacmanGameState> currentState = std::dynamic_pointer_cast<CPacmanGameState>(getState());

        // Manejar la entrada del usuario
        currentState->vHandleInput();

        // Actualizar la lógica del juego
        currentState->vUpdate(deltaTime.asSeconds());

        m_rwWindow.clear();
        // Dibujar la escena

        currentState->vDraw(m_rwWindow);

        m_rwWindow.display();

        
    }
}


CPacmanGameManager& CPacmanGameManager::getInstance()
{
    static CPacmanGameManager instance;
    return instance;
}