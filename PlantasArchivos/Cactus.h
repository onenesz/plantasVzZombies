
#ifndef PVZ_CACTUS_H
#define PVZ_CACTUS_H

#include "Planta.h"

class Cactus : public Planta {

public:
    Cactus():Planta('c', 100, 0, 120, 25, "Planta Cactus"){}
    int activar() override;
};


#endif //PVZ_CACTUS_H