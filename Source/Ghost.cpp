#include "../Include/PacManHeaderLib.h"
#include "../Include/PacmanScene.h"
#include <cmath>

CGhost::CGhost()
{
    m_fSpeed = 0.0f;
    m_vDirection = sf::Vector2f(0.0f, 0.0f);
    m_vPosition = sf::Vector2i(0, 0);
    m_sprSprite = sf::Sprite();
    m_fScaredTimer = 0.0f;
    m_fRandomTimer = 0.0f;
    m_eCurrentState = EGSTATE::CHASING;
}

CGhost::CGhost(sf::Vector2i vStartPosition,
    sf::Vector2f vStartDirection,
    float fStartingSpeed,
    sf::Sprite sprGhostSprite,
    float fRandomTimer,
    float fScaredTimer,
    CGhost::EGSTATE eCurrentState)
{
    m_vPosition = vStartPosition;
    m_vDirection = vStartDirection;
    m_fSpeed = fStartingSpeed;
    m_sprSprite = sf::Sprite(sprGhostSprite);
    m_fScaredTimer = fScaredTimer;
    m_fRandomTimer = fRandomTimer;
    m_eCurrentState = eCurrentState;
}

void CGhost::vUpdate(float fDeltaTime)
{
    // Obtener la posición del jugador
    std::shared_ptr<MichGF::CScene> pScene = CGameManager::getInstance().getScene(); // Obtener la escena como shared_ptr
    std::shared_ptr<CPlayer> pPlayer = pScene->getEntity<CPlayer>();

    if (pPlayer != nullptr) {
        std::shared_ptr<MichGF::CTransformComponent> pPlayerTransform = pPlayer->getComponent<MichGF::CTransformComponent>();
        if (pPlayerTransform != nullptr) {
            sf::Vector2f playerPosition = pPlayerTransform->vGetPosition();

            // Lógica para elegir el comportamiento del fantasma
            switch (m_eCurrentState) {
            case EGSTATE::CHASING:
                vChasePac(playerPosition, fDeltaTime);
                break;
            case EGSTATE::SCARED:
                vScared(playerPosition, fDeltaTime);
                break;
            case EGSTATE::SCATTER:
                vScatter(playerPosition, fDeltaTime); // Implementar la lógica de dispersión
                break;
            case EGSTATE::DEAD:
                vReturnToBase(playerPosition, fDeltaTime); // Implementar la lógica de regresar a la base
                break;
            }
        }
    }
}

void CGhost::vChasePac(const sf::Vector2f& vPlayerPosition, float fDeltaTime)
{
    // Obtener el componente TransformComponent del fantasma
    std::shared_ptr<MichGF::CTransformComponent> pTransform = getComponent<MichGF::CTransformComponent>();

    // Calcular la dirección hacia el jugador
    sf::Vector2f direction = vPlayerPosition - pTransform->vGetPosition();
    direction = normalize(direction); // Normalizar la dirección

    // Actualizar la posición del fantasma
    sf::Vector2f newPosition = pTransform->vGetPosition() + direction * m_fSpeed * fDeltaTime; // Asegúrate de tener fDeltaTime disponible
    pTransform->vSetPosition(newPosition);
}

void CGhost::vScared(const sf::Vector2f& vPlayerPosition, float fDeltaTime)
{
    // Obtener el componente TransformComponent del fantasma
    std::shared_ptr<MichGF::CTransformComponent> pTransform = getComponent<MichGF::CTransformComponent>();


    // Calcular la dirección opuesta al jugador
    sf::Vector2f direction = pTransform->vGetPosition() - vPlayerPosition;
    direction = normalize(direction); // Normalizar la dirección

    // Actualizar la posición del fantasma
    sf::Vector2f newPosition = pTransform->vGetPosition() + direction * m_fSpeed * fDeltaTime; // Asegúrate de tener fDeltaTime disponible
    pTransform->vSetPosition(newPosition);
}

sf::Vector2f CGhost::normalize(const sf::Vector2f& v)
{
    float length = std::sqrt(v.x * v.x + v.y * v.y);
    if (length != 0.0f) {
        return sf::Vector2f(v.x / length, v.y / length);
    }
    else {
        return sf::Vector2f(0.0f, 0.0f);
    }
}

void CGhost::vReturnToBase(const sf::Vector2f& vPlayerPosition, float fDeltaTime)
{
    // Obtener el componente TransformComponent del fantasma
    std::shared_ptr<MichGF::CTransformComponent> pTransform = getComponent<MichGF::CTransformComponent>();

    std::shared_ptr<MichGF::CScene> pScene = CGameManager::getInstance().getScene();

    sf::Vector2f vBasePosition = std::dynamic_pointer_cast<CPacmanScene>(pScene)->vGetBasePos(); // Usar dynamic_pointer_cast

    // Calcular la dirección hacia la base
    sf::Vector2f direction = vBasePosition - pTransform->vGetPosition();
    direction = normalize(direction); // Normalizar la dirección

    // Actualizar la posición del fantasma
    sf::Vector2f newPosition = pTransform->vGetPosition() + direction * m_fSpeed * fDeltaTime;
    pTransform->vSetPosition(newPosition);

    // Verificar si el fantasma ha llegado a la base
    sf::Vector2f ghostPosition = pTransform->vGetPosition();
    float distanceToBase = std::sqrt(
        (vBasePosition.x - ghostPosition.x) * (vBasePosition.x - ghostPosition.x) +
        (vBasePosition.y - ghostPosition.y) * (vBasePosition.y - ghostPosition.y)
    );

    if (distanceToBase < 5.0f) { // Ejemplo: Umbral de 5 píxeles
        // El fantasma ha llegado a la base

        // Cambiar el estado del fantasma a Disperso
        m_eCurrentState = EGSTATE::SCATTER;

        // (Opcional) Reiniciar el temporizador de movimiento aleatorio
        m_fRandomTimer = 0.0f;
    }
}

void CGhost::vScatter(const sf::Vector2f& vPlayerPosition, float fDeltaTime)
{
}

void CGhost::vMove(float fDeltaTime)
{
    // Obtener el componente TransformComponent
    std::shared_ptr<MichGF::CTransformComponent> pTransform = getComponent<MichGF::CTransformComponent>();

    // 1. Perseguir al jugador
    std::shared_ptr<MichGF::CScene> pScene = CGameManager::getInstance().getScene(); // Obtener la escena como shared_ptr
    std::shared_ptr<CPlayer> pPlayer = pScene->getEntity<CPlayer>(); // Obtener la entidad del jugador
    if (pPlayer != nullptr) {  // Verificar que el jugador existe
        std::shared_ptr<MichGF::CTransformComponent> pPlayerTransform = pPlayer->getComponent<MichGF::CTransformComponent>(); // Obtener el TransformComponent del jugador
        if (pPlayerTransform != nullptr)
        { // Verificar que el jugador tiene TransformComponent
            sf::Vector2f playerPosition = pPlayerTransform->vGetPosition(); // Obtener la posición del jugador
            sf::Vector2f direction = playerPosition - pTransform->vGetPosition();
            direction = normalize(direction);

            // 2. Moverse aleatoriamente
            if (m_fRandomTimer <= 0.0f)
            {
                // Generar un número aleatorio entre 0 y 3
                int iRandomDirection = rand() % 4;

                // Asignar la dirección en función del número aleatorio
                switch (iRandomDirection) {
                case 0: m_vDirection = sf::Vector2f(-1.0f, 0.0f); break; // Izquierda
                case 1: m_vDirection = sf::Vector2f(1.0f, 0.0f); break; // Derecha
                case 2: m_vDirection = sf::Vector2f(0.0f, -1.0f); break; // Arriba
                case 3: m_vDirection = sf::Vector2f(0.0f, 1.0f); break; // Abajo
                }

                m_fRandomTimer = 1.0f; // Reiniciar el temporizador (1 segundo)
            }
            else {
                m_fRandomTimer -= fDeltaTime; // Decrementar el temporizador
            }

            // 3. Patrullar un área (ejemplo simple)
            // ...

            // Actualizar la posición del fantasma
            sf::Vector2f newPosition = pTransform->vGetPosition() + direction * m_fSpeed * fDeltaTime;
            pTransform->vSetPosition(newPosition);
        }
    }
}


CGhost::~CGhost()
{
    //distroy Everything
}