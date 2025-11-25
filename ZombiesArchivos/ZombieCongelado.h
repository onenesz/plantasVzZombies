#ifndef PVZ_ZOMBIECONGELADO_H
#define PVZ_ZOMBIECONGELADO_H

#include "Zombie.h"

class ZombieCongelado : public Zombie {
public:
    ZombieCongelado(int _fila):Zombie('L', 150, 15, 2,_fila) {}

    int mover () override;
    void atacar(Planta *_planta) override;
    void habilidadEspecial() override; //QUEDA PENDIENTE HASTA HACER LA PLANTA DE HIELO
};

#endif //PVZ_ZOMBIECONGELADO_H