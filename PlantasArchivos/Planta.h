
#ifndef PVZ_PLANTA_H
#define PVZ_PLANTA_H

#include <iostream>
using namespace std;

class Planta {
protected:
    char icono;
    int costoSoles;
    int alcance;
    int vida;
    int danio;
public:
    Planta(char _icono, int _costoSoles, int _alcance, int _vida, int _danio): icono(_icono), costoSoles(_costoSoles), alcance(_alcance), vida(_vida), danio(_danio) {}
    virtual ~Planta() = default;
    virtual int activar() = 0;

    //GETTERS
    int getCosto() const { return costoSoles; }
    int getVida() const { return vida; }
    char getIcono() const { return icono; }

    //SETTERS
    void recibirDanio(int cantidad);

};





#endif //PVZ_PLANTA_H