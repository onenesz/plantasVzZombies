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

void Juego::siguienteTurno() {
    cout << "\n--- TURNO " << turnoActual << " ---" << endl;
    turnoActual++;

    // TURNO DE LAS PLANTAS
    for (int i = 0; i < tablero->getFila(); i++) {
        for (int j = 0; j < tablero->getColumna(); j++) {

            Planta* _planta = tablero->getPlanta(i, j);

            if (_planta != nullptr) {
                int resultado = _planta->activar();
                if (resultado > 0) {
                    soles += resultado; // Girasol
                    cout << "Girasol genero soles" << endl;
                } else if (resultado == -1) {
                    // CherryBomb (Explosión)
                }

                for (Zombie* z : zombies) {
                    bool mismaFila = (z->getFila() == i);
                    int distancia = z->getColumna() - j; //DISTANCIA (ZOMBIE - PLANTA)
                    bool dentroRango = (distancia >= 0 && distancia <= _planta->getAlcance());

                    if (mismaFila && dentroRango) {
                        _planta->atacar(z);
                    }
                }
            }
        }
    }

    // TURNO DE LOS ZOMBIES
    for (Zombie* z : zombies) {

        Planta* plantaEnPosicion = tablero->getPlanta(z->getFila(), z->getColumna());

        if (plantaEnPosicion != nullptr) {
            cout << "Zombie atacando planta en (" << z->getFila() << "," << z->getColumna() << ")" << endl;
            z->atacar(plantaEnPosicion);
        } else {
            int pasos = z -> mover();
            if (pasos > 0) {
                z->aplicarMovimiento(pasos);
            }
        }

        if (z->getColumna() < 0) {
            cout << "\n=========================================" << endl;
            cout << "      ¡LOS ZOMBIS ENTRARON A LA CASA!      " << endl;
            cout << "                 GAME OVER                 " << endl;
            cout << "===========================================" << endl;
            exit(0);
        }
    }
    auto posZombies = zombies.begin();
    while (posZombies != zombies.end()) {
        if ((*posZombies)->getVida() <= 0) {
            cout << "¡Un zombie ha muerto!" << endl;
            delete *posZombies;
            posZombies = zombies.erase(posZombies);
        } else {
            ++posZombies;
        }
    }

    for (int i = 0; i < tablero->getFila(); i++) {
        for (int j = 0; j < tablero->getColumna(); j++) {
            Planta* _planta = tablero->getPlanta(i, j);
            if (_planta != nullptr && _planta->getVida() <= 0) {
                cout << "Una planta ha muerto en (" << i << "," << j << ")" << endl;
                delete _planta;
                tablero->eliminarPlanta(i, j);
            }
        }
    }
    if (rand() % 5 == 0) {
        crearZombie();
    }
}

void Juego::crearZombie() {

    int fila = rand() % 5;
    Zombie* nuevo = nullptr;

    int tipo = rand() % 100;

    if (tipo < 25) {
        nuevo = new ZombieRapido(fila);
    } else if (tipo < 50) {
        nuevo = new ZombieCasco(fila);
    } else if (tipo < 75) {
        nuevo = new ZombieSaltador(fila);
    } else if (tipo < 90){
        nuevo = new ZombieCongelado(fila);
    } else {
        nuevo = new ZombieYeti(fila);
    }

    zombies.push_back(nuevo);
    cout << "Ha aparecido un " << nuevo -> getNombre() << endl;
}

void Juego::colocarPlanta() {
    //MODIFICAR LA CANTIDAD DE SOLES NECESARIOS PARA CADA PLANTA
    int opcion;
    cout << "\n----- COLOCAR PLANTAS (Soles: " << soles << ") -----" << endl;
    cout << "1. Girasol (x soles)" << endl;
    cout << "2. Seta Defensiva (x soles)" << endl;
    cout << "3. Cactus (x soles)" << endl;
    cout << "4. Planta Hielo (x soles)" << endl;
    cout << "5. CherryBomb (x soles)" << endl;
    cout << "0. Cancelar" << endl;

    cout << "Elige una planta:";
    cin >> opcion;

    if (opcion == 0)
        return;

    //INICIALIZAMOS LAS VARIABLES
    Planta* plantaEleccion = nullptr;
    int costo = 0;

    switch (opcion) {
        case 1: plantaEleccion = new Girasol();
            costo = 50;
            break;
        case 2: plantaEleccion = new SetaDefensiva();
            costo = 50;
            break;
        case 3: plantaEleccion = new Cactus();
            costo = 100;
            break;
        case 4: plantaEleccion = new PlantaHielo();
            costo = 150;
            break;
        case 5: plantaEleccion = new CherryBomb();
            costo = 150;
            break;
        default:
            cout << "Opcion invalida, vuelva a intentar" << endl;
            return;
    }

    if (soles < costo) {
        cout << "No tienes suficientes soles (Tienes: " << soles << ", Necesitas: " << costo << ")" << endl;
        delete plantaEleccion;
        return;
    }

    int fila, columna;
    cout << "Ingresa Fila (0-4) y Columna (0-8):";
    cin >> fila >> columna;

    if (tablero->estaVacia(fila, columna)) {
        tablero->colocarPlanta(plantaEleccion, fila, columna);
        soles -= costo;
        cout << "Planta "<< plantaEleccion -> getNombre() << " ha sido colocada!" << endl;
    } else {
        cout << "Esta casilla ya esta ocupada o fuera de rango!" << endl;
        delete plantaEleccion;
    }
}