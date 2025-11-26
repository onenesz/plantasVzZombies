
#ifndef PVZ_JUEGO_H
#define PVZ_JUEGO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "../TableroArchivos/Tablero.h"
#include "../ZombiesArchivos/zombiesTotales.h"
#include "../PlantasArchivos/plantasTotales.h"

class Juego {
private:
    Tablero* tablero;
    vector<Zombie*> zombies;
    int soles;
    int oleadas;
    int turnoActual;
    const int TURNOS_MAXIMOS = 100;

public:
    Juego():tablero(new Tablero), soles(50), oleadas(1), turnoActual(1) {}
    ~Juego();

    void mostrarMenu();
    void jugar();
    void siguienteTurno();
    void mostrarDatos();
    void crearZombie();
    void colocarPlanta();
};



#endif //PVZ_JUEGO_H