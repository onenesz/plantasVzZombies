#include "ZombieCasco.h"

//void ZombieCasco:: habilidadEspecial () {
   // cout << "Con su ventisca de hielo emerge y a las plantas lentas hace";}

bool ZombieCasco:: mover(int _contarTurnos, int velocidad) {
    contarTurnos++;
    if (contarTurnos >= velocidad) {
        contarTurnos = 0;
        return true;} return false;
}

void ZombieCasco:: atacar(Planta* _planta) {
    _planta->recibirDanio(danio);
}