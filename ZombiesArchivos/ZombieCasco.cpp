#include "ZombieCasco.h"
#include "../PlantasArchivos/Planta.h"

int ZombieCasco:: mover() {
    contarTurnos++;
    if (contarTurnos >= velocidad) {
        contarTurnos = 0;
        return 1;
    }
    return 0;
}

void ZombieCasco:: atacar(Planta* _planta) {
    _planta->recibirDanio(danio);
}

void ZombieCasco::recibirDanio (int danioPlanta) {
    if (turnosAtaques < 3) {
        cout << "El casco del zombie lo protege!" << endl;
        vida -= danioPlanta * 0.5;
        turnosAtaques++;
    } else {
        cout << "Se rompio el casco!" << endl;
        vida -= danioPlanta;
    }
}

void ZombieCasco::habilidadEspecial() {}

