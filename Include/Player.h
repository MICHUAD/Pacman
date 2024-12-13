#pragma once
#include "../GameFramework/Include/Entity.h"

class CPlayer : public MichGF::CEntity
{
public:
    CPlayer();
    CPlayer(sf::Vector2i vStartPosition, sf::Vector2f vStartDirection, float fStartingSpeed, sf::Sprite sprPlayerSprite);
    ~CPlayer();
    void vUpdate(float fDeltaTime) override;
    void vHandleInput();
    void vMove(float fDeltaTime);

    void vSetDirection(sf::Vector2f vDirection) { m_vDirection = vDirection; }

protected:
    float m_fSpeed;
    sf::Vector2f m_vDirection;

};

