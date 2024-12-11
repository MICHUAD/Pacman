#pragma once
namespace MichGF
{
	class CGameManager
	{
    public:
        static CGameManager& getInstance(); // Método estático para obtener la instancia

        void vRun();

    private:
        CGameManager(); // Constructor privado
        CGameManager(const CGameManager&) = delete; // Evitar copia
        CGameManager& operator=(const CGameManager&) = delete; // Evitar asignación

        void vInit();
        void vHandleInput();
        void vUpdate(float fDeltaTime);
        void vDraw();

        sf::RenderWindow m_rwWindow; // Ventana del juego
        std::shared_ptr<CScene> m_pCurrentScene; // Escena actual
        std::shared_ptr<CState> m_pCurrentState; // Estado actual
        sf::Clock m_cClock; // Reloj para medir el tiempo
	};
}