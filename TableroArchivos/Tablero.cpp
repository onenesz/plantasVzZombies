#include "Tablero.h"

bool Tablero::estaVacia(int _fila, int _colum) {
    if (_fila >= 0 && _fila < fila && _colum >= 0 && _colum < columna) {
        if (tabla[_fila][_colum] == nullptr)
            return true;
        else
            return false;
    }
    return false;
}

void Tablero::colocarPlanta(Planta* _planta, int _fila, int _columna) {
    if (estaVacia(_fila, _columna)) {
        tabla[_fila][_columna] = _planta;
    }
}

void Tablero::eliminarPlanta(int _fila, int _columna) {
    if (estaVacia(_fila, _columna) == false) {
        tabla[_fila][_columna] = nullptr;
    }
}

Planta* Tablero::getPlanta(int _fila, int _columna) {
    if (_fila >= 0 && _fila < fila && _columna >= 0 && _columna < columna) {
        return tabla[_fila][_columna];
    }
    return nullptr;
}

void Tablero::mostrarTablero(const vector<Zombie*>& zombis) {

    cout << "   ";
    for (int j = 0; j < columna; ++j) {
        cout << j << " ";
    }
    cout << endl;

    for (int i = 0; i < fila; ++i) {
        cout << i << " |";
        for (int j = 0; j < columna; ++j) {

            char dibujo = '.';

            if (tabla[i][j] != nullptr) {
                dibujo = tabla[i][j] -> getIcono();
            }

            for (Zombie* z : zombis) {
                if (z -> getFila() == i && z -> getColumna() == j) {
                    dibujo = z -> getIcono();
                }
            }
            cout << dibujo << " ";
        }
        cout << "|" << endl;
    }
}

