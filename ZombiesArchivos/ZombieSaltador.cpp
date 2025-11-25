#include "ZombieSaltador.h"

int ZombieSaltador:: mover() {
    this->contarTurnos++;
    if (this->contarTurnos == 1 || this->contarTurnos==2) {
        return 1;} else if (this->contarTurnos== 3) {
            this->contarTurnos = 0;
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
        cout << "Zombie Saltador se ha movido a la fila " << this -> fila << endl;
    }
}

void ZombieSaltador :: atacar(Planta* _planta) {
    _planta->recibirDanio(this->danio);
}