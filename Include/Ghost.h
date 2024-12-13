#pragma once
#include "../GameFramework/Include/Entity.h"


class CGhost : public MichGF::CEntity
{

public:
	enum class EGSTATE {
		CHASING,
		SCATTER,
		SCARED,
		DEAD,
	};

	CGhost();
	CGhost(sf::Vector2i vStartPosition, sf::Vector2f vStartDirection, float fStartingSpeed, sf::Sprite sprGhostSprite);
	~CGhost();
	void vUpdate(float fDeltaTime) override;
	void vChasePac(const sf::Vector2f& vPlayerPosition, float fDeltaTime);
	void vScared(const sf::Vector2f& vPlayerPosition, float fDeltaTime);
	void vMove(float fDeltaTime);
	sf::Vector2f normalize(const sf::Vector2f& v);
	void vReturnToBase(const sf::Vector2f& vPlayerPosition, float fDeltaTime);
	void vScatter(const sf::Vector2f& vPlayerPosition, float fDeltaTime);
	EGSTATE eGetCurrentState() { return m_eCurrentState; }
	void vSetCurrentState(EGSTATE eNewState) { m_eCurrentState = eNewState; }

private:
	float m_fSpeed;
	sf::Vector2f m_vDirection;
	float m_fRandomTimer;
	EGSTATE m_eCurrentState;
};

