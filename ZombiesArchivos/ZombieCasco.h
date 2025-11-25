
#ifndef PVZ_ZOMBIECASCO_H
#define PVZ_ZOMBIECASCO_H

#include "Zombie.h"

class ZombieCasco : public Zombie {
    public:
        ZombieCasco():Zombie('*', 200, 30, 1, ){}

        int mover () override;
        void atacar(Planta *_planta) override;

};

#endif //PVZ_ZOMBIECASCO_H