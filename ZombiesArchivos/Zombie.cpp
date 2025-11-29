#include "Zombie.h"
#include "../PlantasArchivos/Planta.h"

ostream& operator<<(ostream& os, const Zombie& zombie) {
    os << zombie.getNombre() << " (" << zombie.getVida() << " VIDA) en [" << zombie.getFila() << ", " << zombie.getColumna() << "]";
    return os;
}

void Zombie::recibirDanio(int danioPlanta) {
    vida -= danioPlanta;
}