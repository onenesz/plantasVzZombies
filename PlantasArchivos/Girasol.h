
#ifndef PVZ_GIRASOL_H
#define PVZ_GIRASOL_H

#include "Planta.h"

class Girasol : public Planta {
private:
    int contadorTurnos;
    int contadorRayo;
public:
    Girasol():Planta('G', 50, 0, 80, 0, "Planta Girasol"){ contadorTurnos = 0; contadorRayo = 0; }
    int activar() override;
};




#endif //PVZ_GIRASOL_H