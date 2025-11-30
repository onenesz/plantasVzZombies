
#ifndef PVZ_PLANTAHIELO_H
#define PVZ_PLANTAHIELO_H

#include "Planta.h"

class PlantaHielo : public Planta {
private:
    int contadorCongelacionTotal;
public:
    PlantaHielo():Planta('H', 225, 0, 100, 15, "Planta Hielo"){ contadorCongelacionTotal = 0; }
    int activar() override;
};

#endif //PVZ_PLANTAHIELO_H