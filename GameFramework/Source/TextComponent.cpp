#include "TextComponent.h"
namespace MichGF {

    CTextComponent::CTextComponent() : m_txtText()
    {
    }

    CTextComponent::CTextComponent(const std::string& sText, const sf::Font& fntFont, int iFontSize) :
        m_txtText(sText, fntFont, iFontSize)
    {
    }

    void CTextComponent::vSetText(const std::string& sText)
    {
        m_txtText.setString(sText);
    }

    std::string CTextComponent::sGetText() const
    {
        return m_txtText.getString();
    }

    void CTextComponent::vSetFont(const sf::Font& fntFont)
    {
        m_txtText.setFont(fntFont);
    }

    sf::Font CTextComponent::fntGetFont() const
    {
        return *m_txtText.getFont();
    }

    void CTextComponent::vSetFontSize(int iFontSize)
    {
        m_txtText.setCharacterSize(iFontSize);
    }

    int CTextComponent::iGetFontSize() const
    {
        return m_txtText.getCharacterSize();
    }

    void CTextComponent::vSetColor(const sf::Color& clrColor)
    {
        m_txtText.setFillColor(clrColor);
    }

    sf::Color CTextComponent::clrGetColor() const
    {
        return m_txtText.getFillColor();
    }

    void CTextComponent::vDraw(sf::RenderWindow& rwWindow)
    {
        rwWindow.draw(m_txtText);
    }

}