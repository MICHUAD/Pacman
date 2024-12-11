#pragma once

#include "../include/HeaderLib.h"

namespace MichGF
{
    class CGraphicsComponent : public MichGF::CComponent
    {
    public:
        CGraphicsComponent() {}
        CGraphicsComponent(const sf::Sprite& sprSprite);

        void vSetSprite(const sf::Sprite& sprSprite) { m_sprSprite = sprSprite; }
        sf::Sprite vGetSprite() const { return m_sprSprite; }

        void vDraw(sf::RenderWindow& rwWindow);

    private:
        sf::Sprite m_sprSprite; // Sprite a dibujar
    };
}