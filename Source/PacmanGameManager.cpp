#include "../Include/PacManHeaderLib.h"
#include "../Include/PacmanGameManager.h"
#include "../Include/PacmanGameState.h"
#include <memory>

void CPacmanGameManager::vInit()
{
    // 1. Crear una instancia del estado de juego de Pacman
    std::shared_ptr<CPacmanGameState> pGameState = std::make_shared<CPacmanGameState>(this);

    // 2. Inicializar el estado de juego
    pGameState->vInit();

    // 3. Asignar el estado de juego al GameManager
    m_pCurrentState = pGameState;
}
