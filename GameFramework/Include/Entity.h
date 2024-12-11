#pragma once
#include <SFML/Graphics.hpp>

namespace MichGF // Mich Game Framework, creating a namespace to avoid any library conflict
{
	/*
	*	Base class for all entities in the game, as Pac-man, Ghosts, and elements on the map, like the powr tokens or the cherries
	*	contains the common attributes to all entities.
	*/
	class CEntity
	{
	public:
		//setters for position and sprite avoiding the direct access to the attributes
		void vSetPosition(int fPosX, int fPosY) { m_vPosition.x = fPosX; m_vPosition.y = fPosY; }
		void vSetSprite(const sf::Sprite& sprSprite) { m_sprSprite = sprSprite; }

		//geters get it? xD, return a constant not modificable data, I learn that using it increases the security in the code, avoiding miss rewrites to the attributes
		sf::Vector2i	vGetPosition() const { return m_vPosition; }
		sf::Sprite		vGetSprite() const { return m_sprSprite; }

		//upadte The child should override, the update contains the behavior we need to happen every time on the game loop, like update position if its moving, or update sprite if its an animation of an sprite sheet
		virtual void vUpdate(float fDeltaTime) {}
		//dtaw Draw help us to put the updated data into the screen, in this case the sprite as base.
		void vDraw(sf::RenderWindow& rwWindow) { rwWindow.draw(m_sprSprite); }

		//Using protected level of security so the child can access directly to these attributes without the getter.
	protected:
		sf::Vector2i m_vPosition;
		sf::Sprite m_sprSprite;
	};
}