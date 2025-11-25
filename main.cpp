#include <cstdlib>

#include "JuegoArchivos/Juego.h"
#include <ctime>

int main() {
    srand(time(nullptr));
    Juego juego;
    juego.mostrarMenu();
    return 0;
}