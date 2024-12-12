#pragma once

#include "../include/HeaderLib.h"
#include "GraphicsComponent.h"

namespace MichGF
{
    CGraphicsComponent::CGraphicsComponent(const sf::Sprite& sprSprite) : m_sprSprite(sprSprite)
    {
    }

    CGraphicsComponent::CGraphicsComponent(const sf::Texture& txTexture)
    {
    }

    void CGraphicsComponent::vDraw(sf::RenderWindow& rwWindow)
    {
        // drawing logic -TODO-
        rwWindow.draw(m_sprSprite);
    }
}