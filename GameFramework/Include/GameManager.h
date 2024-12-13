#pragma once
namespace MichGF
{
	class CGameManager
	{
    public:
        static CGameManager& getInstance(); // Método estático para obtener la instancia

        std::shared_ptr<CScene> getScene() const { return m_pCurrentScene; }
        std::shared_ptr<CState> getState() const { return m_pCurrentState; }

        void setScene(std::shared_ptr<CScene> pScene) { m_pCurrentScene = pScene; }

        void setState(std::shared_ptr<CState> pState) { m_pCurrentState = pState; }

       virtual void vRun();

    protected:
        CGameManager(); // Constructor privado
        CGameManager(const CGameManager&) = delete; // Evitar copia
        CGameManager& operator=(const CGameManager&) = delete; // Evitar asignación

        virtual void vInit();
        virtual void vHandleInput();
        virtual void vUpdate(float fDeltaTime);
        virtual void vDraw();

        sf::RenderWindow m_rwWindow; // Ventana del juego
        std::shared_ptr<CScene> m_pCurrentScene; // Escena actual
        std::shared_ptr<CState> m_pCurrentState; // Estado actual
        sf::Clock m_cClock; // Reloj para medir el tiempo
	};
}