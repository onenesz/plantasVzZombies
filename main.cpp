#include <cstdlib>

#include "JuegoArchivos/Juego.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(nullptr));
    Juego juego;
    juego.mostrarMenu();
    return 0;
}