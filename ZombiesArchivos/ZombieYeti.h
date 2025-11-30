
#ifndef PVZ_ZOMBIEYETI_H
#define PVZ_ZOMBIEYETI_H

#include "Zombie.h"

class ZombieYeti : public Zombie {
private:
    int contadorAtaques;
public:
    ZombieYeti(int _fila) : Zombie('Y', 700, 20, 3, _fila, "Zombie Yeti") { alcance = 4; contadorAtaques = 0; }

    int mover() override;
    void atacar(Planta* _planta) override;
    void habilidadEspecial() override;
    void recibirDanio (int danioPlanta) override;
};



#endif //PVZ_ZOMBIEYETI_H