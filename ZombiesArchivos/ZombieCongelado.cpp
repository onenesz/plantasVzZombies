#include "ZombieCongelado.h"

//void ZombieCongelado:: habilidadEspecial () {
   // cout << "Con su ventisca de hielo emerge y a las plantas lentas hace";}

int ZombieCongelado:: mover() {
    this->contarTurnos++;
    if (this -> contarTurnos >= this->velocidad) {
        this -> contarTurnos = 0;
        return this -> pasosPorMovimiento;}
    return 0;
}

void ZombieCongelado:: atacar(Planta* _planta) {
    _planta->recibirDanio(danio);
}