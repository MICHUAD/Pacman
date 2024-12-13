#include "../Include/PacmanGameState.h"
#include "../Include/PacmanGameManager.h" // Asegúrate de incluir la clase específica de PacManGameManager
#include "../Include/PacmanScene.h" // Y la escena de PacMan
#include <memory> // Para usar std::make_shared
#include <list>


CPacmanGameState::CPacmanGameState(MichGF::CGameManager* pGameManager) :
    CState(pGameManager),
    m_iScore(0),
    m_iLives(3),
    m_bGameOver(false)
{
}


void CPacmanGameState::vInit()
{
    // 1. Crear una instancia de la escena de PacMan
    std::shared_ptr<CPacmanScene> pScene = std::make_shared<CPacmanScene>();

    // 2. Configurar la escena (añadir entidades, etc.) - Esto ya lo hace el constructor de CPacmanScene

    // 3. Asignar la escena al GameManager
    m_pGameManager->setScene(pScene);
}

void CPacmanGameState::vHandleInput()
{
    // Obtener la instancia del jugador de la escena
    std::shared_ptr<CPlayer> pPlayer = m_pGameManager->getScene()->getEntity<CPlayer>(); // Asumiendo que tienes un método getEntity() en CScene

    // Mover al jugador con las flechas del teclado
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        pPlayer->vSetDirection(sf::Vector2f(-1.0f, 0.0f)); // Izquierda
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        pPlayer->vSetDirection(sf::Vector2f(1.0f, 0.0f)); // Derecha
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        pPlayer->vSetDirection(sf::Vector2f(0.0f, -1.0f)); // Arriba
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        pPlayer->vSetDirection(sf::Vector2f(0.0f, 1.0f)); // Abajo
    }
}

void CPacmanGameState::vUpdate(float fDeltaTime)
{
    if (!m_bGameOver)
    {
        // Actualizar las entidades de la escena
        m_pGameManager->getScene()->vUpdate(fDeltaTime);

        // Verificar colisiones
        checkCollisions();
    }
}
void CPacmanGameState::checkCollisions()
{
    // Obtener la instancia del jugador de la escena
    std::shared_ptr<CPlayer> pPlayer = m_pGameManager->getScene()->getEntity<CPlayer>();

    // Obtener los fantasmas de la escena
    std::list<std::shared_ptr<CGhost>> ghosts = m_pGameManager->getScene()->getEntities<CGhost>();

    // Detectar colisiones entre el jugador y los fantasmas
    if (pPlayer != nullptr) {
        for (const auto& pGhost : ghosts) {
            if (pPlayer->vGetSprite().getGlobalBounds().intersects(pGhost->vGetSprite().getGlobalBounds())) {
                // El jugador ha colisionado con un fantasma
                if (pGhost->eGetCurrentState() == CGhost::EGSTATE::SCARED) {
                    // El fantasma está asustado, el jugador lo come
                    m_iScore += 100; // Aumentar el puntaje
                    pGhost->vSetCurrentState(CGhost::EGSTATE::DEAD); // Cambiar el estado del fantasma a DEAD
                    // ... (Opcional: Reproducir sonido de comer fantasma) ...
                }
                else {
                    // El fantasma no está asustado, el jugador pierde una vida
                    m_iLives--; // Restar una vida

                    if (m_iLives <= 0) {
                        // El jugador ha perdido todas las vidas
                        m_bGameOver = true;
                        // ... (Opcional: Mostrar mensaje de "Game Over", detener el juego, etc.) ...
                    }
                    else {
                        // Actualizar el mapa con la nueva información del jugador
                        std::shared_ptr<MichGF::CScene> pScene = m_pGameManager->getScene();
                        std::dynamic_pointer_cast<CPacmanScene>(pScene)->vUpdateMap(m_iScore, m_iLives);
                    }
                }
            }
        }
    }

    // Detectar colisiones con las paredes
    std::list<sf::FloatRect> walls = std::dynamic_pointer_cast<CPacmanScene>(m_pGameManager->getScene())->getWalls();
    for (const auto& wall : walls) {
        if (pPlayer->vGetSprite().getGlobalBounds().intersects(wall)) {
            // El jugador ha colisionado con una pared

            // Detener al jugador
            pPlayer->vSetDirection(sf::Vector2f(0.0f, 0.0f));
        }
    }

    // Detectar colisiones con los puntos
    std::list<std::shared_ptr<MichGF::CEntity>> points = std::dynamic_pointer_cast<CPacmanScene>(m_pGameManager->getScene())->getPoints();
    auto itPoint = points.begin();
    while (itPoint != points.end()) {
        if (pPlayer->vGetSprite().getGlobalBounds().intersects((*itPoint)->vGetSprite().getGlobalBounds())) {
            // El jugador ha colisionado con un punto
            m_iScore += 10; // Aumentar el puntaje

            // Eliminar el punto de la escena (m_lEntities)
            m_pGameManager->getScene()->vRemoveEntity(*itPoint);

            // Eliminar el punto de la lista m_lPoints en CPacmanScene
            itPoint = std::dynamic_pointer_cast<CPacmanScene>(m_pGameManager->getScene())->getPoints().erase(itPoint);

            // (Opcional) Reproducir un sonido al comer un punto
            // ... 
        }
        else {
            ++itPoint;
        }
    }

    // Detectar colisiones con las píldoras de poder
    std::list<std::shared_ptr<MichGF::CEntity>> powerPills = std::dynamic_pointer_cast<CPacmanScene>(m_pGameManager->getScene())->getPowerPills();
    auto itPowerPill = powerPills.begin();
    while (itPowerPill != powerPills.end()) {
        if (pPlayer->vGetSprite().getGlobalBounds().intersects((*itPowerPill)->vGetSprite().getGlobalBounds())) {
            // El jugador ha colisionado con una píldora de poder
            m_iScore += 50; // Aumentar el puntaje

            // Eliminar la píldora de la escena (m_lEntities)
            m_pGameManager->getScene()->vRemoveEntity(*itPowerPill);

            // Eliminar la píldora de la lista m_lPowerPills en CPacmanScene
            itPowerPill = std::dynamic_pointer_cast<CPacmanScene>(m_pGameManager->getScene())->getPowerPills().erase(itPowerPill);

            // Activar el estado de vulnerabilidad de los fantasmas
            for (const auto& pGhost : ghosts) {
                pGhost->vSetCurrentState(CGhost::EGSTATE::SCARED);
                // ... (Opcional: Cambiar el sprite del fantasma, reproducir un sonido) ...
            }

            // (Opcional) Iniciar un temporizador para controlar la duración del estado de vulnerabilidad
            // ...
        }
        else {
            ++itPowerPill;
        }
    }
}
void CPacmanGameState::vDraw(sf::RenderWindow& rwWindow)
{
    // Aquí se dibujan elementos específicos del estado de juego, si es necesario.
    // ... (Por ahora, no necesitamos dibujar nada adicional aquí) ...
}
