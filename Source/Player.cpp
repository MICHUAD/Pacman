#include "../Include/PacManHeaderLib.h"

CPlayer::CPlayer()
{
    m_fSpeed = 0.0f;
    m_vDirection = sf::Vector2f(0.0f, 0.0f);

}

CPlayer::CPlayer( sf::Vector2f vStartDirection, float fStartingSpeed)
{
    m_vDirection = vStartDirection;
    m_fSpeed = fStartingSpeed;
}

void CPlayer::vUpdate(float fDeltaTime)
{
    vHandleInput();
    vMove(fDeltaTime);
}

void CPlayer::vHandleInput()
{
    // Logic for handling any kwyboard input at first, eventually controler or other gamepath -TODO-
}

void CPlayer::vMove(float fDeltaTime)
{
    // Obtener el componente TransformComponent
    std::shared_ptr<MichGF::CTransformComponent> pTransform = getComponent<MichGF::CTransformComponent>();

    // Calcular la nueva posición
    sf::Vector2f newPosition = pTransform->vGetPosition() + m_vDirection * m_fSpeed * fDeltaTime;

    // Actualizar la posición del jugador
    pTransform->vSetPosition(newPosition);
}
CPlayer::~CPlayer()
{
    //somehting to destroy eventually
}