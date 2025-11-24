
#ifndef PVZ_SETADEFENSIVA_H
#define PVZ_SETADEFENSIVA_H

#include "Planta.h"

class SetaDefensiva : public Planta {

public:
    SetaDefensiva():Planta('S', 50, 0, 150, 0){}
    int activar() override;
};





#endif //PVZ_SETADEFENSIVA_H