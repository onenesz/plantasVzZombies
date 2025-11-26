
#ifndef PVZ_PLANTA_H
#define PVZ_PLANTA_H
#include "../ZombiesArchivos/Zombie.h"
#include <iostream>
using namespace std;

class Planta {
protected:
    string nombre;
    char icono;
    int costoSoles;
    int alcance;
    int vida;
    int danio;
public:
    Planta(char _icono, int _costoSoles, int _alcance, int _vida, int _danio, string _nombre): icono(_icono), costoSoles(_costoSoles), alcance(_alcance),
    vida(_vida), danio(_danio), nombre(_nombre) {}
    virtual ~Planta() = default;
    virtual int activar() = 0;
    virtual void atacar(Zombie* zombie){}

    //GETTERS
    int getCosto() const { return costoSoles; }
    int getVida() const { return vida; }
    char getIcono() const { return icono; }
    int getDanio() const { return danio; }
    int getAlcance() const { return alcance; }
    string getNombre() const { return nombre; }

    //SETTERS
    void recibirDanio(int cantidad);

};





#endif //PVZ_PLANTA_H