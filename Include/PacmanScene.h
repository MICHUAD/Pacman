#pragma once
#include "PacManHeaderLib.h"

class CPacmanScene : public MichGF::CScene
{
public:
    CPacmanScene();

    void vLoadMap(const std::string& sFilename); // Método para cargar el mapa

private:
    // Aquí puedes añadir atributos específicos de la escena de PacMan,
    // como el mapa del juego, la posición de los objetos, etc.
};

