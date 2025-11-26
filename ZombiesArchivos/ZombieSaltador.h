
#ifndef PVZ_ZOMBIESALTADOR_H
#define PVZ_ZOMBIESALTADOR_H
#include "Zombie.h"

class ZombieSaltador : public Zombie {
public:
    ZombieSaltador(int _fila) : Zombie('J',120, 10,5, _fila) {}

    int mover() override;
    void atacar(Planta* _planta) override;
    void habilidadEspecial () override;
    void recibirDanio (int danioPlanta) override;


};



#endif //PVZ_ZOMBIESALTADOR_H