#pragma once
#include "PacManHeaderLib.h"

class CPacmanScene : public MichGF::CScene
{
public:
    CPacmanScene();

    void vLoadMap(const std::string& sFilename); // M�todo para cargar el mapa

private:
    // Aqu� puedes a�adir atributos espec�ficos de la escena de PacMan,
    // como el mapa del juego, la posici�n de los objetos, etc.
};

