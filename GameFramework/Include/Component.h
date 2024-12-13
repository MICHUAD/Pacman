#pragma once

namespace MichGF
{
    class CEntity; // forward declaration, used to anticipate the existance of the class (need to be sure is correctly implemented)

    class CComponent
    {
    public:
        CComponent() : m_pEntity(nullptr) {}
        virtual ~CComponent() {}

        virtual void vStart() {}
        virtual void vUpdate(float fDeltaTime) {}
        virtual void vOnCollision(CEntity* pOtherEntity) {}

        void vSetEntity(CEntity* pEntity) { m_pEntity = pEntity; }

        void vSetName(const std::string& sName) { m_sName = sName; }
        const std::string& sGetName() const { return m_sName; }

    protected:
        CEntity* m_pEntity; //pointer to the entity that it belongs.
        std::string m_sName; // Nombre del componente
    };
}