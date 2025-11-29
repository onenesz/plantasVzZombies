
#ifndef PVZ_ZOMBIESALTADOR_H
#define PVZ_ZOMBIESALTADOR_H
#include "Zombie.h"

class ZombieSaltador : public Zombie {
private:
    bool tienePertiga;
public:
    ZombieSaltador(int _fila) : Zombie('J',120, 10,5, _fila, "Zombie Saltador") { tienePertiga = true;}

    int mover() override;
    void atacar(Planta* _planta) override;
    void habilidadEspecial () override;
    void recibirDanio (int danioPlanta) override;
    bool getTienePertiga() { return tienePertiga; }
    void setTienePertiga( bool x) { tienePertiga = x; }

};



#endif //PVZ_ZOMBIESALTADOR_H