#include "PlantaHielo.h"

int PlantaHielo::activar() {
    contadorCongelacionTotal++;
    if (contadorCongelacionTotal >= 4) {
        contadorCongelacionTotal = 0;
        return -2;
    }
    return 0;
}