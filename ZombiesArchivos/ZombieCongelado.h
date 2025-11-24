#ifndef PVZ_ZOMBIECONGELADO_H
#define PVZ_ZOMBIECONGELADO_H

#include "Zombie.h"

class ZombieCongelado : public Zombie {
public:
    ZombieCongelado():Zombie('#', 100, 20, 2){}

    //HABILIDAD ESPECIAL
    //void habilidadEspecial (CTablero tablero, vector<CPLantas> plantas) override;

    bool mover (int _contarTurnos, int _velocidad) override;
    void atacar(Planta *_planta);
};

#endif //PVZ_ZOMBIECONGELADO_H