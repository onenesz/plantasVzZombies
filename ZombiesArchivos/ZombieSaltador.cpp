#include "ZombieSaltador.h"
#include "../PlantasArchivos/Planta.h"

int ZombieSaltador:: mover() {
    contarTurnos++;
    if (contarTurnos >= velocidad) {
        contarTurnos = 0;
        return 1;
    }
    return 0;
}

void ZombieSaltador:: habilidadEspecial() {}

void ZombieSaltador :: atacar(Planta* _planta) {
    _planta->recibirDanio(this->danio);
}

void ZombieSaltador::recibirDanio (int danioPlanta) {
    vida = max(0, vida - danioPlanta);
}