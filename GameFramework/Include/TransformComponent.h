#pragma once

#include "../include/HeaderLib.h"

namespace MichGF
{
    class CTransformComponent : public CComponent
    {
    public:
        CTransformComponent() :
            m_vPosition(0.0f, 0.0f),
            m_fRotation(0.0f),
            m_vScale(1.0f, 1.0f) {}

        void vSetPosition(float fPosX, float fPosY) { m_vPosition.x = fPosX; m_vPosition.y = fPosY; }
        void vSetPosition(const sf::Vector2f& vPosition) { m_vPosition = vPosition; }
        void vSetRotation(float fRotation) { m_fRotation = fRotation; }
        void vSetScale(float fX, float fY) { m_vScale.x = fX; m_vScale.y = fY; }
        void vSetScale(const sf::Vector2f& vScale) { m_vScale = vScale; }

        float fGetRotation() const { return m_fRotation; }
        sf::Vector2f vGetScale() const { return m_vScale; }
        sf::Vector2f vGetPosition() const { return m_vPosition; }
        

        
        

    private:
        float m_fRotation;       
        sf::Vector2f m_vPosition;
        sf::Vector2f m_vScale; 
    };
}
