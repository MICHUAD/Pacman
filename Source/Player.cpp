#include "../Include/PacManHeaderLib.h"

CPlayer::CPlayer()
{
    m_fSpeed = 0.0f;
    m_vDirection = sf::Vector2f(0.0f, 0.0f);
    m_vPosition = sf::Vector2i(0, 0);
    m_sprSprite = sf::Sprite();

}

CPlayer::CPlayer(sf::Vector2i vStartPosition, sf::Vector2f vStartDirection, float fStartingSpeed, sf::Sprite sprPlayerSprite)
{
    m_vPosition = vStartPosition;
    m_vDirection = vStartDirection;
    m_fSpeed = fStartingSpeed;
    m_sprSprite = sf::Sprite(sprPlayerSprite);
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

    // Calcular la nueva posici�n
    sf::Vector2f newPosition = pTransform->vGetPosition() + m_vDirection * m_fSpeed * fDeltaTime;

    // Actualizar la posici�n del jugador
    pTransform->vSetPosition(newPosition);
}
CPlayer::~CPlayer()
{
    //somehting to destroy eventually
}