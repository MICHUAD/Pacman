#pragma once
#include "../include/PacManHeaderLib.h"

class CPacmanGameManager : public MichGF::CGameManager
{
public:
    // ... (Podemos añadir métodos específicos de Pacman aquí si es necesario) ...

private:
    void vInit() override;
    // ... (Podemos añadir más métodos privados si es necesario) ...
};