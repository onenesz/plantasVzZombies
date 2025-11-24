
#ifndef PVZ_ZOMBIERAPIDO_H
#define PVZ_ZOMBIERAPIDO_H

#include "Zombie.h"

class ZombieSaltador : public Zombie {
public:
    class ZombieCasco : public Zombie {
    public:
        ZombieCasco():Zombie('*', 200, 30, 1){}

        //HABILIDAD ESPECIAL
        //void habilidadEspecial (CTablero tablero, vector<CPLantas> plantas) override;

        bool mover (int _contarTurnos, int _velocidad) override;
        void atacar(Planta *_planta);
    };
};


#endif //PVZ_ZOMBIERAPIDO_H