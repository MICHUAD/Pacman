#pragma once
#include <list>
#include <memory>

namespace MichGF
{

	class CScene
	{
    public:
        CScene() {}
        virtual ~CScene();

        void vAddEntity(std::shared_ptr<CEntity> pEntity);
        void vRemoveEntity(std::shared_ptr<CEntity> pEntity);

        void vUpdate(float fDeltaTime);
        void vDraw(sf::RenderWindow& rwWindow);

        std::shared_ptr<CEntity> getEntity(const std::string& sName);

        template<typename T>
        inline std::shared_ptr<T> getEntity()
        {
            {
                auto it = std::find_if(m_lEntities.begin(), m_lEntities.end(),
                    [](const std::shared_ptr<CEntity>& pEntity) { return std::dynamic_pointer_cast<T>(pEntity) != nullptr; });

                if (it != m_lEntities.end()) {
                    return std::dynamic_pointer_cast<T>(*it);
                }
                else {
                    return nullptr;
                }
            }
        }

        template <typename T>
        inline std::list<std::shared_ptr<T>> getEntities()
        {
            std::list<std::shared_ptr<T>> result;
            for (const auto& pEntity : m_lEntities) {
                if (std::shared_ptr<T> pCasted = std::dynamic_pointer_cast<T>(pEntity)) {
                    result.push_back(pCasted);
                }
            }
            return result;
        }



    protected:
        std::list<std::shared_ptr<CEntity>> m_lEntities; 
	};
    
}
