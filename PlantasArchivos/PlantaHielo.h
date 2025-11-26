
#ifndef PVZ_PLANTAHIELO_H
#define PVZ_PLANTAHIELO_H

#include "Planta.h"

class PlantaHielo : public Planta {

public:
    PlantaHielo():Planta('H', 50, 0, 100, 50, "Planta Hielo"){}
    int activar() override;
};

#endif //PVZ_PLANTAHIELO_H