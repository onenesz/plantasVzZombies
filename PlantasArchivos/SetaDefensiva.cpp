#include "SetaDefensiva.h"

int SetaDefensiva::activar() {
    if (this -> vida < 150) {
        vida++;
    }
    cout << "La Seta Defensiva ha recuperado un punto de vida" << endl;
    return 0;
}