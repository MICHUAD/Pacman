
#include "../Include/HeaderLib.h"

namespace MichGF
{
	sf::Vector2f CEntity::vGetPosition()
	{
		sf::Vector2f vCurrPosition;
		for (const auto& component : m_lComponents) {
			if (std::dynamic_pointer_cast<MichGF::CTransformComponent>(component) != nullptr) {
				vCurrPosition = std::dynamic_pointer_cast<MichGF::CTransformComponent>(component)->vGetPosition();
			}
		}
		return vCurrPosition;
	}
	sf::Sprite CEntity::vGetSprite()
	{
		sf::Sprite sSpriteFromGC;
		for (const auto& component : m_lComponents) {
			if (std::dynamic_pointer_cast<MichGF::CGraphicsComponent>(component) != nullptr) {
				sSpriteFromGC = std::dynamic_pointer_cast<MichGF::CGraphicsComponent>(component)->vGetSprite();
			}
		}
		return sSpriteFromGC;
	}
	void CEntity::vSetPosition(int fPosX, int fPosY)
	{
		sf::Vector2f vCurrPosition;
		for (const auto& component : m_lComponents) {
			if (std::dynamic_pointer_cast<MichGF::CTransformComponent>(component) != nullptr) {
				std::dynamic_pointer_cast<MichGF::CTransformComponent>(component)->vSetPosition(fPosX,fPosY);
			}
		}
	}
	void CEntity::vSetSprite( const sf::Sprite& sprSprite)
	{
		sf::Sprite sSpriteFromGC;
		for (const auto& component : m_lComponents) {
			if (std::dynamic_pointer_cast<MichGF::CGraphicsComponent>(component) != nullptr) {
				std::dynamic_pointer_cast<MichGF::CGraphicsComponent>(component)->vSetSprite(sprSprite);
			}
		}
	}


	std::shared_ptr<CEntity> CEntity::getEntity(const std::string& sName, CScene sScene)
	{
		for (const auto& pEntity : sScene.getEntities<CEntity>())
		{
			if (pEntity->sGetName() == sName)
			{
				return pEntity;
			}
		}
	}
	void CEntity::vDraw(sf::RenderWindow& rwWindow)
	{
		m_pGraphicsComponent->vDraw(rwWindow);/*
		for (const auto& component : m_lComponents) {
			if (std::dynamic_pointer_cast<MichGF::CGraphicsComponent>(component) != nullptr) {
				std::dynamic_pointer_cast<MichGF::CGraphicsComponent>(component)->vDraw(rwWindow);
			}
		}*/
	}
	void CEntity::vAddComponent(std::shared_ptr<CComponent> pComponent)
	{
		pComponent->vSetEntity(this);
		m_lComponents.push_back(pComponent);
	}
}
