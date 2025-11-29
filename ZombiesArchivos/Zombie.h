#ifndef PVZ_ZOMBIE_H
#define PVZ_ZOMBIE_H
#include <iostream>
using namespace std;
class Planta;

class Zombie {
protected:
    string nombre;
    char icono;
    int vida;
    int danio;
    int velocidad;          //Turnos que deben pasar para un movimiento
    int contarTurnos;       //Contador de turnos transcurridos
    int alcance;

    //ATRIBUTOS DE POSICION
    int fila, columna;

public:
    Zombie(char _icono, int _vida, int _danio, int _velocidad, int _fila, string _nombre) : icono(_icono), vida(_vida), danio(_danio), velocidad(_velocidad),
    nombre(_nombre), contarTurnos(0), fila(_fila), columna(8), alcance(0) {}

    //DESTRUCTOR
    virtual ~Zombie() = default;

    //ACCIONES
    virtual int mover() = 0;
    void aplicarMovimiento (int pasos) { this->columna -= pasos; }
    virtual void atacar(Planta* _planta) = 0;
    virtual void recibirDanio (int danioPlanta) = 0;

    //HABILIDAD
    virtual void habilidadEspecial () = 0;
    virtual bool esInmuneAlHielo() { return false; }

    //GETTERS
    int getVida() const { return vida; }
    int getDanio() const { return danio; }
    char getIcono() const { return icono; }
    int getFila() const { return fila; }
    int getColumna() const { return columna; }
    string getNombre() const { return nombre; }

    //SOBRECARGA DE OPERADORES
    friend ostream& operator<<(ostream& os, const Zombie& z);

    Zombie& operator-=(int cantidad) {
        this->recibirDanio(cantidad);
        return *this;
    }

    Zombie& operator--() {
        this->columna--;
        return *this;
    }

};

#endif //PVZ_ZOMBIE_H