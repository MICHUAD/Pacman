#include "../include/HeaderLib.h"
namespace MichGF
{
    CScene::~CScene()
    {
        // Los punteros inteligentes se encargan de liberar la memoria de las entidades
    }

    void CScene::vAddEntity(std::shared_ptr<CEntity> pEntity)
    {
        m_lEntities.push_back(pEntity);
    }

    void CScene::vRemoveEntity(std::shared_ptr<CEntity> pEntity)
    {
        m_lEntities.remove(pEntity); // Método eficiente para eliminar de la lista
    }

    void CScene::vUpdate(float fDeltaTime)
    {
        for (auto& pEntity : m_lEntities)
        {
            pEntity->vUpdate(fDeltaTime);
        }
    }

    void CScene::vDraw(sf::RenderWindow& rwWindow)
    {
        for (auto& pEntity : m_lEntities)
        {
            pEntity->vDraw(rwWindow);
        }
    }
}