#ifndef PVZ_ZOMBIE_H
#define PVZ_ZOMBIE_H
#include <iostream>
#include "../PlantasArchivos/Planta.h"
using namespace std;

class Zombie {
protected:
    char icono;
    int vida;
    int danio;
    int velocidad;
    int contarTurnos;
    int fila;
    int columna;
public:
    Zombie(char _icono, int _vida, int _danio, int _velocidad, int _fila, int _columna): icono(_icono), vida(_vida), danio(_danio),
    velocidad(_velocidad), contarTurnos(0), fila(_fila), columna(8) {}
    virtual ~Zombie() = default;
    virtual bool mover(int _contarTurnos, int velocidad)=0;
    virtual void atacar(Planta* _planta) = 0;
    virtual void habilidadEspecial ()=0;


    //SETTER
    void recibirDanio (int danioPlanta);

    //GETTER
    int getVida() const {return vida;}
    int getDanio() const {return danio;}
    char getIcono() const {return icono;}
    int getFila() const { return fila; }
    int getColumna() const { return columna; }

};

#endif //PVZ_ZOMBIE_H