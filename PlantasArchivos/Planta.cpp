#include "Planta.h"

ostream& operator<<(ostream& os, const Planta& p) {
    os << p.getNombre() << " (" << p.getVida() << " HP)";
    return os;
}


void Planta::recibirDanio(int cantidad) {
    vida -= cantidad;
}