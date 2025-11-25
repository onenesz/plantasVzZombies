#include "ZombieYeti.h"

int ZombieYeti::mover() {
    this -> contarTurnos++;
    int pasos = 0;

    if (this -> contarTurnos == 1) {
        pasos = 1;
    } else if (this -> contarTurnos == 2) {
        pasos = 0;
    } else if (this -> contarTurnos == 3) {
        pasos = 2;
        this -> contarTurnos = 0;
    }
    return pasos;
}

void ZombieYeti::atacar(Planta* _planta) {
    _planta->recibirDanio(this->danio);
}
