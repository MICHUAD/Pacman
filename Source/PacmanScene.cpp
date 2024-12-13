
#include "../Include/PacManHeaderLib.h"
#include "../Include/PacmanScene.h"
#include "../GameFramework/Include/TextComponent.h"
#include <fstream>
#include <string>


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

    // Cargar texturas
    sf::Texture txWall, txPoint, txPowerPill, txPacman, txGhost;
    if (!txWall.loadFromFile("Resources/wall.png") ||
        !txPoint.loadFromFile("Resources/point.png") ||
        !txPowerPill.loadFromFile("Resources/power_pill.png") ||
        !txPacman.loadFromFile("Resources/pacman.png") ||
        !txGhost.loadFromFile("Resources/ghost.png"))
    {
        // Manejar error de carga de texturas
        return;
    }


    std::ifstream file(sFilename);
    if (file.is_open())
    {

        std::string line;
        int iRow = 0;
        while (std::getline(file, line))
        {
            for (int iCol = 0; iCol < line.length(); ++iCol)
            {
                char c = line[iCol];
                sf::Vector2f vPosition(iCol * 32.0f, iRow * 32.0f); // Asumiendo celdas de 32x32 píxeles

                switch (c)
                {
                case '|': // Pared
                {
                    std::shared_ptr<MichGF::CEntity> pWall = std::make_shared<MichGF::CEntity>();
                    pWall->vAddComponent(std::make_shared<MichGF::CTransformComponent>(vPosition));
                    pWall->vAddComponent(std::make_shared<MichGF::CGraphicsComponent>(txWall));
                    m_lWalls.push_back(pWall->vGetSprite().getGlobalBounds());
                    vAddEntity(pWall);
                    break;
                }
                case '.': // Punto
                {
                    std::shared_ptr<MichGF::CEntity> pPoint = std::make_shared<MichGF::CEntity>();
                    pPoint->vAddComponent(std::make_shared<MichGF::CTransformComponent>(vPosition));
                    pPoint->vAddComponent(std::make_shared<MichGF::CGraphicsComponent>(txPoint));
                    m_lPoints.push_back(pPoint);
                    vAddEntity(pPoint);
                    break;

                    break;
                }
                case '*': // Píldora de poder
                {
                    std::shared_ptr<MichGF::CEntity> pPowerPill = std::make_shared<MichGF::CEntity>();
                    pPowerPill->vAddComponent(std::make_shared<MichGF::CTransformComponent>(vPosition));
                    pPowerPill->vAddComponent(std::make_shared<MichGF::CGraphicsComponent>(txPowerPill));
                    m_lPowerPills.push_back(pPowerPill);

                    vAddEntity(pPowerPill);
                    break;
                }
                case 'P': // Jugador
                {
                    std::shared_ptr<CPlayer> pPlayer = std::make_shared<CPlayer>();
                    pPlayer->vAddComponent(std::make_shared<MichGF::CTransformComponent>(vPosition));
                    pPlayer->vAddComponent(std::make_shared<MichGF::CGraphicsComponent>(txPacman));
                    vAddEntity(pPlayer);
                    break;
                } 
                case 'B': // Base
                {
                    m_vBasePosition = vPosition; // Guardar la posición de la base

                    // Crear una entidad para la base
                    std::shared_ptr<MichGF::CEntity> pBase = std::make_shared<MichGF::CEntity>();
                    pBase->vAddComponent(std::make_shared<MichGF::CTransformComponent>(vPosition));
                    // ... (opcional) Cargar y configurar el sprite de la base ...
                    vAddEntity(pBase);
                    break;
                }
                case '1': // Fantasma 1
                case '2': // Fantasma 2
                case '3': // Fantasma 3
                case '4': // Fantasma 4
                {
                    std::shared_ptr<CGhost> pGhost = std::make_shared<CGhost>();
                    pGhost->vAddComponent(std::make_shared<MichGF::CTransformComponent>(vPosition));
                    pGhost->vAddComponent(std::make_shared<MichGF::CGraphicsComponent>(txGhost));
                    vAddEntity(pGhost);
                    break;
                }
                }
            }
            iRow++;
        }
        file.close();
    }
}

void CPacmanScene::vUpdateMap(int iScore, int iLives)
{
    // 1. Limpiar la escena actual
    m_lEntities.clear();

    // 2. Cargar el mapa original
    vLoadMap("resources/map.txt");

    // 3. Actualizar el puntaje y las vidas (necesitas una forma de acceder a las entidades del jugador y la UI)
    // ... (Implementar la lógica para actualizar el puntaje y las vidas) ...
    std::shared_ptr<MichGF::CEntity> pScoreText = getEntity("ScoreText");
    std::shared_ptr<MichGF::CEntity> pLivesText = getEntity("LivesText");


    if (pScoreText != nullptr && pLivesText != nullptr) {
        // Asumiendo que las entidades tienen un componente CTextComponent
        std::shared_ptr<MichGF::CTextComponent> pScoreTextComponent = pScoreText->getComponent<MichGF::CTextComponent>();
        std::shared_ptr<MichGF::CTextComponent> pLivesTextComponent = pLivesText->getComponent<MichGF::CTextComponent>();

        if (pScoreTextComponent != nullptr && pLivesTextComponent != nullptr) {
            pScoreTextComponent->vSetText("Score: " + std::to_string(iScore));
            pLivesTextComponent->vSetText("Lives: " + std::to_string(iLives));
        }
    }
}
