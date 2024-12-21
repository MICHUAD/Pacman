#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include <memory>

namespace MichGF // Mich Game Framework, creating a namespace to avoid any library conflict
{
	class CComponent; //FFWD Decl
	class CGraphicsComponent; //FFWD Decl
	class CTransformComponent; //FFWD Decl
	class CScene;
	/*
	*	Base class for all entities in the game, as Pac-man, Ghosts, and elements on the map, like the powr tokens or the cherries
	*	contains the common attributes to all entities.
	*/
	class CEntity
	{
	public:
		//setters for position and sprite avoiding the direct access to the attributes
		void vSetPosition(int fPosX, int fPosY);
		void vSetSprite(const sf::Sprite& sprSprite);
		void vSetName(std::string EntityName) { m_sName = EntityName; }

		//geters get it? xD, return a constant not modificable data, I learn that using it increases the security in the code, avoiding miss rewrites to the attributes
		sf::Vector2f	vGetPosition();
		sf::Sprite		vGetSprite();
		const std::string& sGetName() const { return m_sName; }

		std::shared_ptr<CEntity> getEntity(const std::string& sName, CScene sScene);
		CEntity* getEntity() { return this; }

		//upadte The child should override, the update contains the behavior we need to happen every time on the game loop, like update position if its moving, or update sprite if its an animation of an sprite sheet
		virtual void vUpdate(float fDeltaTime) {}
		//dtaw Draw help us to put the updated data into the screen, in this case the sprite as base.
		void vDraw(sf::RenderWindow& rwWindow);

		//used to add components to an entity
		void vAddComponent(std::shared_ptr<MichGF::CComponent> pComponent);
		void VAddGraphicsComponent(std::shared_ptr<CGraphicsComponent> pComponent) {m_pGraphicsComponent = pComponent;}


		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			auto it = std::find_if(m_lComponents.begin(), m_lComponents.end(),
				[](const std::shared_ptr<CComponent>& pComponent) { return std::dynamic_pointer_cast<T>(pComponent) != nullptr; });

			if (it != m_lComponents.end()) {
				return std::dynamic_pointer_cast<T>(*it);
			}
			else {
				return nullptr;
			}
		}
		

		//Using protected level of security so the child can access directly to these attributes without the getter.
	protected:
		std::list<std::shared_ptr<MichGF::CComponent>> m_lComponents;
		std::string m_sName;
		std::shared_ptr<CGraphicsComponent> m_pGraphicsComponent;
	};
}