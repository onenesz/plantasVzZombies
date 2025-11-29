#include <iostream>
#include <ctime>
#include <cstdlib>
#include "JuegoArchivos/Juego.h"

using namespace std;

int main() {
    srand(time(nullptr));
    Juego juego;
    juego.mostrarMenu();


    return 0;
}