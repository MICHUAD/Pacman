#pragma once

namespace MichGF
{
    class CGameManager; // another FFW Decl

    class CState
    {
    public:
        CState(CGameManager* pGameManager) : m_pGameManager(pGameManager) {}
        virtual ~CState() {}

        virtual void vInit() {} // initial gamestate
        virtual void vHandleInput() {} 
        virtual void vUpdate(float fDeltaTime) {} 
        virtual void vDraw(sf::RenderWindow& rwWindow) {} 

    protected:
        CGameManager* m_pGameManager; // Ptr GameManager
    };
}
