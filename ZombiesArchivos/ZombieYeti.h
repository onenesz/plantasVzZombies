
#ifndef PVZ_ZOMBIEYETI_H
#define PVZ_ZOMBIEYETI_H

#include "Zombie.h"

class ZombieYeti : public Zombie {
public:
    ZombieYeti();
    //FALTA AGREGAR SU HABILIDAD
    void mover();
    void atacarCasa();
    void atacarPlanta();
};



#endif //PVZ_ZOMBIEYETI_H