#include "ZombieSaltador.h"

int ZombieSaltador:: mover() {
    contarTurnos++;
    if (contarTurnos == 1 || contarTurnos==2) {
        return 1;
    } else if (contarTurnos == 3) {
        contarTurnos = 0;
        return 2;
    }
    return 0;
}

void ZombieSaltador:: habilidadEspecial() {
    if (this -> getVida() < 50) {
        int nuevaFila = rand() % 5;
        while (nuevaFila == this -> fila) {
            nuevaFila = rand() % 5;
        }
        this -> fila = nuevaFila;
        cout << "Zombie Saltador se ha movido a la fila " << fila << endl;
    }
}

void ZombieSaltador :: atacar(Planta* _planta) {
    _planta->recibirDanio(this->danio);
}

void ZombieSaltador::recibirDanio (int danioPlanta) {
    vida = max(0, vida - danioPlanta);
}