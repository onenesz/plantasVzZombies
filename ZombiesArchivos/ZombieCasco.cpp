#include "ZombieCasco.h"

//void ZombieCasco:: habilidadEspecial () {
// cout << "Con su ventisca de hielo emerge y a las plantas lentas hace";}
//

int ZombieCasco:: mover() {
    this->contarTurnos++;
    if (this -> contarTurnos >= velocidad) {
        this -> contarTurnos = 0;
        return this -> pasosPorMovimiento;
    } return 0;}

void ZombieCasco:: atacar(Planta* _planta) {
    _planta->recibirDanio(danio);
}

