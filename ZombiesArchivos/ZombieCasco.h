
#ifndef PVZ_ZOMBIECASCO_H
#define PVZ_ZOMBIECASCO_H

#include "Zombie.h"

class ZombieCasco : public Zombie {
private:
    int turnosAtaques;
public:
    ZombieCasco(int _fila):Zombie('*', 200, 30, 1, _fila, "Zombie con Casco"), turnosAtaques(0) {}

    //METODOS
    int mover () override;
    void atacar(Planta *_planta) override;
    void habilidadEspecial() override;
    void recibirDanio (int danioPlanta) override;
};

#endif //PVZ_ZOMBIECASCO_H