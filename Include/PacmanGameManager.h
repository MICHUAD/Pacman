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


    // ... (Podemos a�adir m�todos espec�ficos de Pacman aqu� si es necesario) ...
    static CPacmanGameManager& getInstance();

    void vRun() override;
    void vInit() override;

    virtual void vHandleInput();
    virtual void vUpdate(float fDeltaTime);
    virtual void vDraw();

protected:

   // GAMESTATE m_eCurrentGameState;
    // ... (Podemos a�adir m�s m�todos privados si es necesario) ...
};