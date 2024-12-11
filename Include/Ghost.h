#pragma once
#include "../GameFramework/Include/Entity.h"


class CGhost : public MichGF::CEntity
{

public:
	CGhost();
	CGhost(sf::Vector2i vStartPosition, sf::Vector2f vStartDirection, float fStartingSpeed, sf::Sprite sprGhostSprite);
	~CGhost();
	void vUpdate(float fDeltaTime) override;
	void vChasePac(const sf::Vector2f& vPlayerPosition);
	void vScared(); 

private:
	float m_fSpeed;
	sf::Vector2f m_vDirection;
};

