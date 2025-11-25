
#ifndef PVZ_JUEGO_H
#define PVZ_JUEGO_H

#include <vector>
#include <iostream>
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
    void crearZombie(); //pendiente
    void colocarPlanta(); //pendiente
};



#endif //PVZ_JUEGO_H