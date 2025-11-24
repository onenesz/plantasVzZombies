
#ifndef PVZ_CACTUS_H
#define PVZ_CACTUS_H

#include "Planta.h"

class Cactus : public Planta {

public:
    Cactus():Planta('C', 50, 0, 500, 40){}
    int activar() override;
};


#endif //PVZ_CACTUS_H