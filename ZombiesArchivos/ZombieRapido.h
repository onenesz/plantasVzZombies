
#ifndef PVZ_ZOMBIERAPIDO_H
#define PVZ_ZOMBIERAPIDO_H

#include "Zombie.h"

class ZombieRapido : public Zombie {
private:
    int turnosRapido;
    int velocidadAcumulable;
public:
    ZombieRapido(int _fila) : Zombie('R', 70, 5, 1, _fila), turnosRapido(0), velocidadAcumulable(0) {}
    int mover () override;
    void atacar(Planta *_planta) override;
    void habilidadEspecial() override;
};


#endif //PVZ_ZOMBIERAPIDO_H