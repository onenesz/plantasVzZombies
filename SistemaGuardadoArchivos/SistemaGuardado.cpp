#include "SistemaGuardado.h"
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
using namespace std;

SistemaGuardado::SistemaGuardado () :
        nombreJugador(""),
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
        this -> fecha=f.fecha;
}

void SistemaGuardado::guardarpartida(string nombreArchivo) const {
        fstream archivo(nombreArchivo, ios::out);

        if (!archivo.is_open()) {
                cout << "Error al abrir el archivo" << endl;
                return;
        }

        archivo << "Fecha: " << fecha;
        archivo << "Nombre: " << nombreJugador << endl;
        archivo << "Oleadas: " << oleadasCompletadas << endl;
        archivo << "Zombies: " << zombisEliminados << endl;
        archivo << "Soles: " << solesRecolectados << endl;
        archivo << "Danio: " << danioRecibido << endl;
        archivo << "Puntos: " << puntosFinales << endl;

        archivo.close();
        cout << "Partida guardada :D" << endl;

}

bool SistemaGuardado::cargarpartida(string nombreArchivo) {
        ifstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
                cout << "No se encontro archivo de guardado." << endl;
                return false;
        }

        archivo.ignore(100, ':');
        archivo.get();            // Salta el espacio en blanco
        getline(archivo, fecha);  // Lee la fecha

        archivo.ignore(100, ':');
        archivo.get();
        getline(archivo, nombreJugador);

        archivo.ignore(100, ':'); archivo >> oleadasCompletadas;
        archivo.ignore(100, ':'); archivo >> zombisEliminados;
        archivo.ignore(100, ':'); archivo >> solesRecolectados;
        archivo.ignore(100, ':'); archivo >> danioRecibido;
        archivo.ignore(100, ':'); archivo >> puntosFinales;

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
