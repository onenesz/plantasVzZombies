#ifndef PVZ_ZOMBIECONGELADO_H
#define PVZ_ZOMBIECONGELADO_H

#include "Zombie.h"

class ZombieCongelado : public Zombie {
public:
    ZombieCongelado(int _fila):Zombie('L', 150, 15, 2,_fila, "Zombie Congelado") {}

    int mover () override;
    void atacar(Planta *_planta) override;
    void recibirDanio (int danioPlanta) override;
    void habilidadEspecial() override;
    bool esInmuneAlHielo() override { return true; }
};

#endif //PVZ_ZOMBIECONGELADO_H