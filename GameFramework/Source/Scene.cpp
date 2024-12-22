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

    std::shared_ptr<CEntity> CScene::getEntity(const std::string& sName)
    {
        auto it = std::find_if(m_lEntities.begin(), m_lEntities.end(),
            [&sName](const std::shared_ptr<CEntity>& pEntity) {
                // Obtener el nombre del componente
                std::string componentName = pEntity->sGetName();
                return componentName == sName;
            });

        if (it != m_lEntities.end()) {
            return *it;
        }
        else {
            return nullptr;
        }
    }
}