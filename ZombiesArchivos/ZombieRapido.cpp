#include "ZombieRapido.h"

//void ZombieCasco:: habilidadEspecial () {
   // cout << "Con su ventisca de hielo emerge y a las plantas lentas hace";}

int ZombieRapido::mover() {
    this -> contarTurnos++;
    if (this -> contarTurnos >= this->velocidad) {
        this -> contarTurnos = 0;
        return this -> pasosPorMovimiento;
    } return 0;}

void ZombieRapido :: atacar (Planta* _planta) {
    _planta->recibirDanio(danio);
}