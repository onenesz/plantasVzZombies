
#ifndef PVZ_CHERRYBOMB_H
#define PVZ_CHERRYBOMB_H

#include "Planta.h"

class CherryBomb : public Planta{
public:
    CherryBomb():Planta('b', 150, 0, 100, 1000, "Planta Cherry Bomb"){}
    int activar() override;
};


#endif //PVZ_CHERRYBOMB_H