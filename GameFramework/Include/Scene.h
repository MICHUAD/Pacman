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

    private:
        std::list<std::shared_ptr<CEntity>> m_lEntities; 
	};
}
