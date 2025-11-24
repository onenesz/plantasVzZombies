#include "Girasol.h"

int Girasol::activar() {
    contadorTurnos++;
    if (contadorTurnos >= 2 ) {
        contadorTurnos = 0;
        return 25;
    }
    return 0;
}