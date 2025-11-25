
#ifndef PVZ_ZOMBIESALTADOR_H
#define PVZ_ZOMBIESALTADOR_H
#include "Zombie.h"

class ZombieSaltador : public Zombie {
public:
    ZombieSaltador() : Zombie('J',120, 10,5,3) {}

    int mover() override;

    void atacar(Planta* _planta) override;

    void habilidadEspecial () override;



};



#endif //PVZ_ZOMBIESALTADOR_H