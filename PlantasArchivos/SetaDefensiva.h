
#ifndef PVZ_SETADEFENSIVA_H
#define PVZ_SETADEFENSIVA_H

#include "Planta.h"

class SetaDefensiva : public Planta {

public:
    SetaDefensiva():Planta('S', 50, 0, 300, 0, "Planta Seta Defensiva"){}
    int activar() override;
};





#endif //PVZ_SETADEFENSIVA_H