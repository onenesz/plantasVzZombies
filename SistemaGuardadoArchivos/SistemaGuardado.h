#ifndef PVZ_SISTEMAGUARDADO_H
#define PVZ_SISTEMAGUARDADO_H
#include <string>
using namespace std;

struct Fecha {
    string fecha;
    Fecha() {
        time_t t;
        time(&t);
        fecha = ctime(&t);
    }
};

class SistemaGuardado {
private:
    string nombreJugador;
    string fecha;
    int oleadasCompletadas;
    int zombisEliminados;
    int solesRecolectados;
    int danioRecibido;
    int puntosFinales;

public:
    SistemaGuardado();

    void setDatos(string _nombreJugador, int _oleadas, int _zombies, int _soles, int _danio, int _puntos);
    void guardarpartida(string nombreArchivo) const;
    bool cargarpartida(string nombreArchivo);

    void mostrardatos()const;

    //GETTERS
    string getNombreJugador()const {return nombreJugador;}
    string getFecha()const {return fecha;}
    int getOleadasCompletadas()const {return oleadasCompletadas;}
    int getZombiesEliminados()const {return zombisEliminados;}
    int getSolesRecolectados()const {return solesRecolectados;}
    int getDaniosRecibido()const {return danioRecibido;}
    int getPuntosFinales()const {return puntosFinales;}
};


#endif //PVZ_SISTEMAGUARDADO_H