
#ifndef PVZ_ZOMBIEYETI_H
#define PVZ_ZOMBIEYETI_H

#include "Zombie.h"

class ZombieYeti : public Zombie {
public:
    ZombieYeti() : Zombie('Y', 300, 30, 3, ) {}


    int mover() override;
    void atacar(Planta* _planta) override;
    void habilidadEspecial() override;
};



#endif //PVZ_ZOMBIEYETI_H