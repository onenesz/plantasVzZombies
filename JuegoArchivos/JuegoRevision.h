#ifndef PVZ_JUEGO_H
#define PVZ_JUEGO_H
#include <vector>

#include "../TableroArchivos/Tablero.h"
#include "../ZombiesArchivos/zombiesTotales.h"
#include "../PlantasArchivos/plantasTotales.h"

using namespace std;

class Juego {
private:
    Tablero* tablero;
    vector<Zombie*> zombies;
    int soles;
    int oleadas;
    int puntos;
    int turnoActual;
    const int TURNOS_MAXIMOS = 100;
    SistemaGuardado* sistema_;

    //NUEVOS ATRIBUTOS PARA EL GUARDADO
    int zombiesEliminados;
    int danioRecibido;
    string nombreUsuario;

public:
    //SU INICIALIZACIÓN
    Juego():tablero(new Tablero), soles(50), oleadas(1), puntos(0), turnoActual(1),
    sistema_(new SistemaGuardado()), zombiesEliminados(0), danioRecibido(0) {}

    ~Juego();

    void mostrarMenu();
    void jugar();
    void siguienteTurno();

    void guardarDatos ();
    void guardarJuego();
    void cargarJuego();
    void actualizarDatos();

    void mostrarDatos() const;

    void crearZombie();
    void colocarPlanta();
    void removerPlanta ();

};



#endif //PVZ_JUEGO_H