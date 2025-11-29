#include "ZombieYeti.h"
#include "../PlantasArchivos/Planta.h"
6
int ZombieYeti::mover() {
    this->contarTurnos++;
    if (this->contarTurnos >= velocidad) {
        this->contarTurnos = 0;
        return 1;
    }
    return 0;
}

//HACER LA FUNCION
void ZombieYeti::atacar(Planta* _planta) {
    cout << "El Yeti lanza una bola de nieve!" << endl;
    _planta -> recibirDanio(danio);
}

void ZombieYeti::habilidadEspecial() {}

void ZombieYeti::recibirDanio (int danioPlanta) {
    vida = max(0, vida - danioPlanta);
}