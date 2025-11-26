#include "Zombie.h"
#include "../PlantasArchivos/Planta.h"

void Zombie::recibirDanio(int danioPlanta) {
    vida -= danioPlanta;
}