#ifndef TABLEROARCHIVOS_TABLERO_H
#define TABLEROARCHIVOS_TABLERO_H

#include <iostream>
#include "../PlantasArchivos/Planta.h"
#include "../ZombiesArchivos/Zombie.h"
#include <vector>
using namespace std;

class Tablero {
private:
    vector<vector<Planta*>> tabla;
    int fila, columna;

public:
    Tablero():fila(9), columna(5){};
    ~Tablero() = default;
    void mostrarTablero(const vector<Zombie*>& zombis);
    bool estaVacia(int _fila, int _columna);
    void colocarPlanta(Planta* _planta, int _fila, int _columna);
    void eliminarPlanta(int _fila, int _columna);
    Planta* getPlanta(int _fila, int _columna);
};

#endif //TABLEROARCHIVOS_TABLERO_H