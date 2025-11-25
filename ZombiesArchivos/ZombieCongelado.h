#ifndef PVZ_ZOMBIECONGELADO_H
#define PVZ_ZOMBIECONGELADO_H

#include "Zombie.h"

class ZombieCongelado : public Zombie {
public:
    ZombieCongelado():Zombie('L', 150, 15, 2,1){}
    int mover () override;
    void atacar(Planta *_planta) override;
};

#endif //PVZ_ZOMBIECONGELADO_H