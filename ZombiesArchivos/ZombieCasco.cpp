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
    cout << "Exploto el zombie con casco por el danio de " << _planta->getNombre() << "!" << endl;
    _planta->recibirDanio(1000);
    this->vida = 0;
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

