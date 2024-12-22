#pragma once
#include "../include/PacManHeaderLib.h"

class CPacmanGameManager : public MichGF::CGameManager
{
public:
    /*
    enum class GAMESTATE {
        TITLE,
        GAME,
        GAMEOVER
    };
    */


    // ... (Podemos añadir métodos específicos de Pacman aquí si es necesario) ...
    static CPacmanGameManager& getInstance();

    void vRun() override;
    void vInit() override;

    virtual void vHandleInput();
    virtual void vUpdate(float fDeltaTime);
    virtual void vDraw();

protected:

   // GAMESTATE m_eCurrentGameState;
    // ... (Podemos añadir más métodos privados si es necesario) ...
};