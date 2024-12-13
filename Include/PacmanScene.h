#pragma once

#include "PacManHeaderLib.h"
#include <list>
using namespace MichGF;

class CPacmanScene : public CScene
{
public:
    CPacmanScene();
    void vLoadMap(const std::string& sFilename); // Método para cargar el mapa
    void vUpdateMap(int iScore, int iLives);
    sf::Vector2f vGetBasePos() { return m_vBasePosition; }

    std::list<sf::FloatRect> getWalls() const { return m_lWalls; }
    std::list<std::shared_ptr<MichGF::CEntity>> getPoints() const { return m_lPoints; }
    std::list<std::shared_ptr<MichGF::CEntity>> getPowerPills() const { return m_lPowerPills; }

private:
    sf::Vector2f m_vBasePosition;
    std::list<sf::FloatRect> m_lWalls;        // Lista de rectángulos de las paredes
    std::list<std::shared_ptr<MichGF::CEntity>> m_lPoints;      // Lista de entidades de los puntos
    std::list<std::shared_ptr<MichGF::CEntity>> m_lPowerPills; // Lista de entidades de las píldoras de poder


};

