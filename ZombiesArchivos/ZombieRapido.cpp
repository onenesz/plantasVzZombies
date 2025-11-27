#include "ZombieRapido.h"
#include "../PlantasArchivos/Planta.h"

int ZombieRapido::mover() {
    contarTurnos++; int pasosAvanzar = 0;
    if (contarTurnos >= velocidad) {
        contarTurnos = 0;
        turnosRapido++;

        pasosAvanzar = 1;
        if (turnosRapido % 3 == 0) {
            cout << "¡El Zombie Rápido ya te alcanzara!" << endl;
            velocidadAcumulable++;
            pasosAvanzar += velocidadAcumulable;
        }
        return pasosAvanzar;
    }
    return pasosAvanzar;
}

void ZombieRapido :: atacar (Planta* _planta) {
    _planta->recibirDanio(danio);
}

void ZombieRapido::habilidadEspecial() {}

void ZombieRapido::recibirDanio (int danioPlanta) {
    vida = max(0, vida - danioPlanta);
}