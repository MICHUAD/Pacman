#pragma once

#include "../include/HeaderLib.h"

namespace MichGF
{
    CGraphicsComponent::CGraphicsComponent(const sf::Sprite& sprSprite) : m_sprSprite(sprSprite)
    {
    }

    void CGraphicsComponent::vDraw(sf::RenderWindow& rwWindow)
    {
        // drawing logic -TODO-
        rwWindow.draw(m_sprSprite);
    }
}