
#ifndef PVZ_ZOMBIERAPIDO_H
#define PVZ_ZOMBIERAPIDO_H

#include "Zombie.h"

class ZombieRapido : public Zombie {
public:
    ZombieRapido():Zombie('R', 70, 5, 1, 2){}
    int mover () override;
    void atacar(Planta *_planta) override;

    };


#endif //PVZ_ZOMBIERAPIDO_H