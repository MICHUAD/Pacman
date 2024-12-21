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
        m_sprSprite.setTexture(txTexture);
    }


    void CGraphicsComponent::vDraw(sf::RenderWindow& rwWindow)
    {
        // Obtener la entidad a la que pertenece este componente
        MichGF::CEntity* pEntity = m_pEntity->getEntity();
        
        if (pEntity != nullptr) {
            // Obtener el sprite de la entidad
            sf::Sprite entitySprite = pEntity->vGetSprite();
            
            // Actualizar la textura del sprite (si es necesario)
            // entitySprite.setTexture(m_txTexture);

            // Obtener el TransformComponent de la entidad
            std::shared_ptr<MichGF::CTransformComponent> pTransform = pEntity->getComponent<MichGF::CTransformComponent>();
            if (pTransform != nullptr) {
                // Establecer la posición del sprite
                entitySprite.setPosition(pTransform->vGetPosition());
            }

            // Dibujar el sprite en la ventana
            rwWindow.draw(entitySprite);
        }
    }
}