#include "ZombieYeti.h"

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
    cout << "El Yeti lanza una bola de nieve a la planta!" << endl;
    _planta -> recibirDanio(this -> danio);
}

void ZombieYeti::habilidadEspecial() {}