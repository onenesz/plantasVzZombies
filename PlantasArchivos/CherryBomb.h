
#ifndef PVZ_CHERRYBOMB_H
#define PVZ_CHERRYBOMB_H

#include "Planta.h"

class CherryBomb : public Planta{
public:
    CherryBomb():Planta('B', 50, 0, 100, 0){}
    int activar() override;
};


#endif //PVZ_CHERRYBOMB_H