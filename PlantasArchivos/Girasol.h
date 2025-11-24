
#ifndef PVZ_GIRASOL_H
#define PVZ_GIRASOL_H

#include "Planta.h"

class Girasol : public Planta {
private:
    int contadorTurnos;
public:
    Girasol():Planta('G', 50, 0, 100, 0){ contadorTurnos = 0; }
    int activar() override;
};




#endif //PVZ_GIRASOL_H