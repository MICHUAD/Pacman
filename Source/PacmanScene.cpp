
#include "../Include/PacManHeaderLib.h"

CPacmanScene::CPacmanScene()
{
    // 1. Cargar el mapa del juego
    vLoadMap("resources/map.txt");

    // 2. Crear al jugador
    std::shared_ptr<CPlayer> pPlayer = std::make_shared<CPlayer>();
    // Configurar la posición inicial, sprite, etc. del jugador
    vAddEntity(pPlayer);

    // 3. Crear los fantasmas
    std::shared_ptr<CGhost> pGhost1 = std::make_shared<CGhost>();
    // Configurar la posición inicial, sprite, etc. del fantasma 1
    vAddEntity(pGhost1);

    // ... Crear los demás fantasmas ...
}

void CPacmanScene::vLoadMap(const std::string& sFilename)
{
    std::ifstream file(sFilename);
    if (file.is_open())
    {
        // Leer el archivo del mapa y crear las entidades del mapa (paredes, puntos, etc.)
        // ...
        file.close();
    }
}
