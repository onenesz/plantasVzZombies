#include "Juego.h"

Juego::~Juego() {
    delete tablero;
    for (Zombie* z : zombies) {
        delete z;
    }
    zombies.clear();
}

void Juego::mostrarMenu() {
    int opcion = 0 ;

    do {
        cout << "------------------------------------\n";
        cout << "-------- PLANTAS VS ZOMBIES --------\n";
        cout << "------------------------------------\n";
        cout << "1. Jugar" << endl;
        cout << "2. Ver Datos" << endl;
        cout << "3. Salir" << endl;
        cout << "-------> Elige una opcion <-------" << endl; cin >> opcion;
        switch(opcion) {
            case 1:
                jugar();
                break;
            case 2:
                mostrarDatos();
                break;
            case 3:
                cout << "***** Saliste, gracias por jugar! *****" << endl;
            default:
                cout << "Opcion incorrecta, digite otra vez" << endl;
        }
    }while(opcion != 3);
}

void Juego::jugar() {
    int opcion;
    do {
        tablero -> mostrarTablero(zombies);
        cout << "\n--- TURNO ---" << endl;
        cout << "1. Siguiente Turno (No hacer nada)" << endl;
        cout << "2. Plantar" << endl;
        cout << "3. Volver al Menu" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                siguienteTurno();
                break;
            case 2:
                colocarPlanta();
                break;
            case 3:
                cout << "***** Volviste al menu! *****" << endl;
                break;
            case 4:
                cout << "Opcion incorrecta, digite otra vez" << endl;
                break;
        }
    }while (opcion != 3);
}

void Juego::mostrarDatos() {
    cout << "Soles: " << soles << ", Oleada: " << oleadas << endl;
}

//MODIFICAR MAS ADELANTE  ------>
void Juego::siguienteTurno() {

    for (Zombie* zomb : zombies) {
        zomb ->mover();
    }

    if (rand() % 10 == 0) {
        crearZombie();
    }
}

void Juego::crearZombie() {

    Zombie* nuevo = new ZombieCasco(rand() % 5);
    zombies.push_back(nuevo);

    // cout << "Un zombie ha aparecido " << endl;
}

void Juego::colocarPlanta() {
}
