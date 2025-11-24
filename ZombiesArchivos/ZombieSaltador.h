
#ifndef PVZ_ZOMBIESALTADOR_H
#define PVZ_ZOMBIESALTADOR_H

#include "Zombie.h"

class ZombieSaltador : public Zombie {
public:
    ZombieSaltador();
    //FALTA AGREGAR SU HABILIDAD
    void mover();
    void atacarCasa();
    void atacarPlanta();
};



#endif //PVZ_ZOMBIESALTADOR_H