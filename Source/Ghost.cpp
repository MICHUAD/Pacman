#include "../Include/PacManHeaderLib.h"

CGhost::CGhost()
{
    m_fSpeed = 0.0f;
    m_vDirection = sf::Vector2f(0.0f, 0.0f);
    m_vPosition = sf::Vector2i(0, 0);
    m_sprSprite = sf::Sprite();
}

CGhost::CGhost(sf::Vector2i vStartPosition, sf::Vector2f vStartDirection, float fStartingSpeed, sf::Sprite sprGhostSprite)
{
    m_vPosition = vStartPosition;
    m_vDirection = vStartDirection;
    m_fSpeed = fStartingSpeed;
    m_sprSprite = sf::Sprite(sprGhostSprite);
}

void CGhost::vUpdate(float fDeltaTime)
{
}

void CGhost::vChasePac(const sf::Vector2f& vPlayerPosition)
{
    //logic for chasing
}

void CGhost::vScared()
{
    //logic for run away when pacman take the PILL!!!!
}

CGhost::~CGhost()
{
    //distroy Everything
}