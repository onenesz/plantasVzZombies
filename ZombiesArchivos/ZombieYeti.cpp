#include "ZombieYeti.h"
#include "../PlantasArchivos/Planta.h"

int ZombieYeti::mover() {
    this->contarTurnos++;
    if (this->contarTurnos >= velocidad) {
        this->contarTurnos = 0;
        return 1;
    }
    return 0;
}

void ZombieYeti::atacar(Planta* _planta) {
    contadorAtaques++;
    cout << "El Yeti lanza una bola de nieve!" << endl;
    _planta -> recibirDanio(danio);

    if (contadorAtaques >= 3) {
        cout << "El Yeti realiza un ataque doble!" << endl;
        _planta->recibirDanio(danio);
        contadorAtaques = 0;
    }
}

void ZombieYeti::habilidadEspecial() {}

void ZombieYeti::recibirDanio (int danioPlanta) {
    vida = max(0, vida - danioPlanta);
}