#include "ZombieCongelado.h"
#include "../PlantasArchivos/Planta.h"

int ZombieCongelado:: mover() {
    contarTurnos++;
    if (contarTurnos >= velocidad) {
        contarTurnos = 0;
        return 1;
    }
    return 0;
}

void ZombieCongelado:: atacar(Planta* _planta) {
    _planta -> recibirDanio(danio);
}

void ZombieCongelado::habilidadEspecial() {
    cout << "Con su ventisca de hielo emerge y a las plantas lentas hace" << endl;
}

void ZombieCongelado::recibirDanio (int danioPlanta) {
    vida = max(0, vida - danioPlanta);
}