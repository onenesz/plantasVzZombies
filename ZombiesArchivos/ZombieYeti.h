
#ifndef PVZ_ZOMBIEYETI_H
#define PVZ_ZOMBIEYETI_H

#include "Zombie.h"

class ZombieYeti : public Zombie {
public:
    ZombieYeti(int _fila) : Zombie('Y', 300, 30, 3, _fila) { alcance = 4; }

    int mover() override;
    void atacar(Planta* _planta) override;
    void habilidadEspecial() override;
    void recibirDanio (int danioPlanta) override;
};



#endif //PVZ_ZOMBIEYETI_H