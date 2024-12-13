#pragma once
#include  <SFML/Graphics.hpp>
#include "Component.h"

namespace MichGF
{
	class CTextComponent : public MichGF::CComponent
	{
    public:
        CTextComponent();
        CTextComponent(const std::string& sText, const sf::Font& fntFont, int iFontSize);

        void vSetText(const std::string& sText);
        std::string sGetText() const;

        void vSetFont(const sf::Font& fntFont);
        sf::Font fntGetFont() const;

        void vSetFontSize(int iFontSize);
        int iGetFontSize() const;

        void vSetColor(const sf::Color& clrColor);
        sf::Color clrGetColor() const;

        void vDraw(sf::RenderWindow& rwWindow);

    protected:
        sf::Text m_txtText;

	};
}