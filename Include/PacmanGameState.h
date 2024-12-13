#pragma once
#include "PacManHeaderLib.h"


class CPacmanGameState : public MichGF::CState
{
public:
    CPacmanGameState(MichGF::CGameManager* pGameManager);

    void vInit() override;
    void vHandleInput() override;
    void vUpdate(float fDeltaTime) override;
    void checkCollisions();
    void vDraw(sf::RenderWindow& rwWindow) override;

private:
    // Atributos para el estado del juego
    int m_iScore;
    int m_iLives;
    bool m_bGameOver;
};

