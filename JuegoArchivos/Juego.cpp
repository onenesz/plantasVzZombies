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
        cout << "3. Cargar juego" << endl;
        cout << "4. Salir" << endl;
        cout << "-------> Elige una opcion <-------" << endl;

        if (!(cin >> opcion)) {
            cout << "Error, debes ingresar un numero ( 1-4 )" << endl;
            cin.clear(); // Limpia el estado de error
            cin.ignore(10000, '\n'); // Borra el texto basura del buffer
            opcion = -1; // Pone un valor invalido para que el bucle se repita
            continue;
        }

        switch(opcion) {
            case 1:
                jugar();
                break;
            case 2:
                mostrarDatos();
                break;
            case 3:
                cargarJuego();
                break;
            case 4:
                cout << "***** Saliste, gracias por jugar! *****" << endl;
                break;
            default:
                cout << "Opcion incorrecta, digite otra vez" << endl;
                break;
        }
    }while(opcion != 4);
}

void Juego::jugar() {
    int opcion;
    do {
        tablero -> mostrarTablero(zombies);
        cout << "\n--- TURNO ---" << endl;
        cout << "1. Siguiente Turno (No hacer nada)" << endl;
        cout << "2. Plantar" << endl;
        cout << "3. Remover Planta" << endl;
        cout << "4. Guardar Partida" << endl;
        cout << "5. Volver al Menu" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                siguienteTurno();
                break;
            case 2:
                colocarPlanta();
                break;
            case 3:
                removerPlanta();
                break;
            case 4:
                guardarJuego();
                break;
            case 5:
                cout << "***** Volviste al menu! *****" << endl;
                break;
            default:
                cout << "Opcion incorrecta, digite otra vez" << endl;
                break;
        }
    }while (opcion != 5);
}

void Juego::mostrarDatos() {
    cout << "\n======== ESTADO DE LAS PLANTAS Y ZOMBIES ========" << endl;
    cout << " Soles: " << soles
         << " Oleada: " << oleadas
         << " Turno: " << turnoActual << endl;
    cout << "===================================================" << endl;

    if (zombies.empty()) {
        cout << "No hay zombis" << endl;
    } else {
        cout << " Zombis atacando (" << zombies.size() << "):" << endl;
        for (Zombie* z : zombies) {
            cout << "  - " << *z << endl;
        }
    }

    cout << " Plantas defendiendo:" << endl;
    bool hayPlantas = false;
    for (int i = 0; i < tablero->getFila(); i++) {
        for (int j = 0; j < tablero->getColumna(); j++) {
            Planta* p = tablero->getPlanta(i, j);
            if (p != nullptr) {
                cout << "   -> [" << i + 1 << "," << j + 1 << "] " << *p << endl;
                hayPlantas = true;
            }
        }
    }
    if (!hayPlantas)
        cout << "  No hay plantas" << endl;

    cout << "===================================================\n" << endl;
}

void Juego::siguienteTurno() {
    cout << "\n--- TURNO " << turnoActual << " ---" << endl;
    turnoActual++; contadorSolesCaidos++;

    if (contadorSolesCaidos >= 3) {
        soles += 25;
        contadorSolesCaidos = 0;
    }

    bool hayHielo = false, congelacionGlobal = false;

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
                    cout << "El CherryBomb ha explotado" << endl;
                    for (Zombie* z : zombies) {
                        //EL DANIO DEL CHERRYBOMB SE HACE EN UN 3 X 3
                        int distanciaFila = abs(z->getFila() - i);
                        int distanciaCol = abs(z->getColumna() - j);
                        if (distanciaFila <= 1 && distanciaCol <= 1)
                            *z -= 1000;
                    }
                } else if (resultado == -2) {
                    congelacionGlobal = true;
                    cout << "Congelacion total activada!" << endl;
                }
                else if (resultado == -3) {
                    cout << "Girasol ha activador rayo solar en la fila " << i + 1 << "!" << endl;
                    for (Zombie* z : zombies) {
                        if (z->getFila() == i) {
                            cout << " -> " << z -> getNombre() << " recibe daño solar" << endl;
                            *z -= 50;
                        }
                    }
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

        if (z->getVida() <= 0) continue;

        if (congelacionGlobal) {
            if (!z->esInmuneAlHielo()) {
                cout << z->getNombre() << " por la congelacion total no se mueve!" << endl;
                continue;
            }
        }

        hayHielo = false;
        for(int j = 0; j < tablero->getColumna(); j++) {
            Planta* p = tablero->getPlanta(z->getFila(), j);
            if (p != nullptr && p->getNombre() == "Planta Hielo") { //
                hayHielo = true;
                break;
            }
        }

        if (hayHielo && rand() % 2 == 0) {
            cout << *z << " esta congelado y no se mueve por la Planta Hielo!" << endl;
            continue;
        }

        Planta* plantaEnPosicion = tablero->getPlanta(z->getFila(), z->getColumna());

        if (plantaEnPosicion != nullptr) {

            ZombieSaltador* saltador = dynamic_cast<ZombieSaltador*>(z); //Verificamos si z es un zombie saltador
            if (saltador != nullptr && saltador->getTienePertiga()) {
                cout << z->getNombre() << " ha saltado con su pertiga" << endl;
                saltador->setTienePertiga(false);
                z->aplicarMovimiento(2);
            } else {
                cout << "Zombie atacando planta en (" << z->getFila() << "," << z->getColumna() << ")" << endl;
                z->atacar(plantaEnPosicion);

                if (plantaEnPosicion->getNombre() == "Planta Cactus") {
                    cout << "El zombi se pincho con el Cactus" << endl;
                    *z -= plantaEnPosicion -> getDanio();
                }
            }
        } else {
            int pasos = z -> mover();
            if (pasos > 0) {
                for(int i = 0; i < pasos; i++) {
                    --(*z);
                    Planta* plantaChoque = tablero->getPlanta(z->getFila(), z->getColumna());
                    if (plantaChoque != nullptr) {
                        break; //EL ZOMBIE PARA PORQUE HAY UNA PLANTA EN SU CAMINO
                    }
                    if (z->getColumna() < 0) {
                        break;
                    }
                }
            }
        }

        //----------------------------------------------------------------------------------------------------
        if (z->getColumna() < 0) {
            cout << "\n=========================================" << endl;
            cout << "      LOS ZOMBIS ENTRARON A LA CASA!      " << endl;
            cout << "                GAME OVER                 " << endl;
            cout << "==========================================" << endl;
            exit(0);
        }
    }
    //LIMPIEZA DE ZOMBIES Y PLANTAS
    auto posZombies = zombies.begin();
    while (posZombies != zombies.end()) {
        if ((*posZombies)->getVida() <= 0) {
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
                delete _planta;
                tablero->eliminarPlanta(i, j);
            }
        }
    }
    //---------------------------------------------------------------------------------

    if (rand() % 3 == 0) {
        crearZombie();
    }

    //CONDICION DE VICTORIA
    if (turnoActual >= TURNOS_MAXIMOS && zombies.empty()) {
        cout << "\n=======================================" << endl;
        cout << "                VICTORIA!               " << endl;
        cout << "========================================" << endl;
        exit(0);
    }

    //ESTADO DE LAS PLANTAS Y ZOMBIES
    mostrarDatos();
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

    int opcion;
    do {
        cout << "\n----- COLOCAR PLANTAS (Soles: " << soles << ") -----" << endl;
        cout << "1. Girasol (50 soles)" << endl;
        cout << "2. Seta Defensiva (50 soles)" << endl;
        cout << "3. Cactus (100 soles)" << endl;
        cout << "4. Planta Hielo (175 soles)" << endl;
        cout << "5. CherryBomb (150 soles)" << endl;
        cout << "0. Cancelar" << endl;

        cout << "Elige una planta:";

        if (!(cin >> opcion)) {
            cout << "Error, debes ingresar un numero" << endl;
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(10000, '\n'); // Ignora lo que escribio el usuario hasta el enter
            opcion = -1; // Mantenemos el valor invalido para repetir el bucle
            continue;
        }

        if (opcion < 0 || opcion > 5) {
            cout << "Opcion incorrecta, elige entre 0 y 5" << endl;
        }

    }while ( opcion < 0 || opcion > 5 );

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
            costo = 175;
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
    cout << "Ingresa Fila (1-5) y Columna (1-9):";
    cin >> fila >> columna;

    fila--;
    columna--;

    if (tablero->estaVacia(fila, columna)) {
        tablero->colocarPlanta(plantaEleccion, fila, columna);
        soles -= costo;
        cout << "Planta "<< plantaEleccion -> getNombre() << " ha sido colocada!" << endl;
    } else {
        cout << "Esta casilla ya esta ocupada o fuera de rango!" << endl;
        delete plantaEleccion;
    }
}

void Juego::removerPlanta() {
    int filaIngresada, columnaIngresada;
    int filaReal, columnaReal;

    tablero->mostrarTablero(zombies);

    cout << "\n----- REMOVER PLANTA -----" << endl;
    cout << "Ingresa la fila (1-5) y columna (1-9) de la planta:";
    cout << "Fila: ";

    //EVITAR INGRESO DE DATOS NO NUMERICOS
    if (!(cin >> filaIngresada)) {
        cout << "Entrada invalida. Intentelo nuevamente." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    if (!(cin>>columnaIngresada)) {
        cout << "Entrada invalida. Intentelo nuevamente." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    filaReal=filaIngresada - 1;
    columnaReal=columnaIngresada - 1;

    if (filaReal < 0 || filaReal >= tablero->getFila()
        || columnaReal < 0 || columnaReal >= tablero->getColumna()) {
        cout << "Las coordenadas ingresadas estan fuera del rango." << endl;
        return;
        }

    Planta* plantaRemover = tablero->getPlanta(filaReal, columnaReal);

    if (plantaRemover == nullptr) {
        cout << "No se ha encontrado ninguna planta";
    } else {
        delete plantaRemover;
        tablero->eliminarPlanta(filaReal, columnaReal);
        cout << "Planta removida correctamente" << endl;
    }
}

void Juego::guardarDatos() {

    puntos = (oleadas * 100) + (zombiesEliminados * 10) - (danioRecibido/2);

    sistema_->setDatos(
        nombreUsuario,
        oleadas,
        zombiesEliminados,
        soles,
        danioRecibido,
        puntos);
}

void Juego::guardarJuego() {
    string nombreArchivo;
    cout <<"\n---------- GUARDAR PARTIDA ----------" << endl;
    cout << "Ingresa el nombre para su archivo de guardado (ej. MiPartida.txt): ";

    //getline para leer nombres con espacios, o cin que no esperen espacios
    cin.ignore();     //Limpia el buffer de cualquier salto de linea del cin anterior
    getline(cin, nombreArchivo);

    guardarDatos();
    sistema_->guardarpartida(nombreArchivo);
}

void Juego::cargarJuego() {
    string nombreArchivo;
    cout <<"\n---------- CARGAR PARTIDA ----------" << endl;
    cout << "Ingresa el nombre del archivo a cargar (ej. MiPartida.txt): ";

    cin.ignore();
    getline(cin, nombreArchivo);

    if (sistema_->cargarpartida(nombreArchivo)) {
        sistema_->mostrardatos();

        this->soles = sistema_->getSolesRecolectados();
        this->oleadas = sistema_->getOleadasCompletadas();
        this->nombreUsuario = sistema_->getNombreJugador();
        this->zombiesEliminados = sistema_->getZombiesEliminados();
        this->danioRecibido = sistema_->getDaniosRecibido();
        this->puntos = sistema_->getPuntosFinales();


        cout << "Partida cargada con éxito. Continuando el juego..." << endl;
        jugar();
    } else {
        cout << "No se pudo cargar la partida de nombre: " << nombreArchivo << endl;
    }
}
