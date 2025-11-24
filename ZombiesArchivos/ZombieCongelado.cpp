#include "ZombieCongelado.h"

//void ZombieCongelado:: habilidadEspecial () {
   // cout << "Con su ventisca de hielo emerge y a las plantas lentas hace";}

bool ZombieCongelado:: mover(int _contarTurnos, int velocidad) {
    contarTurnos++;
    if (contarTurnos >= velocidad) {
        contarTurnos = 0;
        return true;} return false;
}

void ZombieCongelado:: atacar(Planta* _planta) {
    _planta->recibirDanio(danio);
}