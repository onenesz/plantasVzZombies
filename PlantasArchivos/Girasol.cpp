#include "Girasol.h"

int Girasol::activar() {
    contadorTurnos++;
    contadorRayo++;
    if (contadorRayo >= 5) {
        contadorRayo = 0;
        return -3;
    }
    if (contadorTurnos >= 2 ) {
        contadorTurnos = 0;
        return 25;
    }
    return 0;
}