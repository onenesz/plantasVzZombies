#include "SistemaGuardado.h"
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
using namespace std;

SistemaGuardado::SistemaGuardado () :
        nombreJugador (""),
        fecha(""),
        oleadasCompletadas(),
        zombisEliminados(),
        solesRecolectados(),
        danioRecibido (),
        puntosFinales ()
{}

void SistemaGuardado::setDatos(string _nJugador, int _oleadas, int _zombies, int _soles, int _danio, int _puntos) {
        nombreJugador = _nJugador;
        oleadasCompletadas = _oleadas;
        zombisEliminados = _zombies;
        solesRecolectados = _soles;
        danioRecibido = _danio;
        puntosFinales = _puntos;
        Fecha f;
        this->fecha=f.fecha;
}

void SistemaGuardado::guardarpartida(string nombreArchivo) const {
        fstream archivo(nombreArchivo, ios::out);

        if (!archivo.is_open()) {
                cout << "Error al abrir el archivo" << endl;
                return;
        }

        archivo << fecha << endl;
        archivo << nombreJugador << endl;
        archivo << oleadasCompletadas << endl;
        archivo << zombisEliminados << endl;
        archivo << solesRecolectados << endl;
        archivo << danioRecibido << endl;
        archivo << puntosFinales << endl;

        archivo.close();
        cout << "Partida guardada :D" << endl;

}

bool SistemaGuardado::cargarpartida(string nombreArchivo) {
        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
                cout << "No se encontro archivo de guardado." << endl;
                return false;
        }

        getline(archivo, fecha);
        getline(archivo, nombreJugador);
        archivo >> oleadasCompletadas;
        archivo >> zombisEliminados;
        archivo >> solesRecolectados;
        archivo >> danioRecibido;
        archivo >> puntosFinales;

        archivo.close();
        return true;
}

void SistemaGuardado::mostrardatos() const {
        cout << "------Datos de la Partida------" << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Jugador: " << nombreJugador << endl;
        cout << "Oleadas completadas: " << oleadasCompletadas << endl;
        cout << "Zombis eliminados: " << zombisEliminados << endl;
        cout << "Soles recolectados: " << solesRecolectados << endl;
        cout << "Dano recibido: " << danioRecibido << endl;
        cout << "Puntos finales: " << puntosFinales << endl;
        cout << "---------------------------" << endl;
}
