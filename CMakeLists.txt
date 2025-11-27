cmake_minimum_required(VERSION 4.0)
project(pvz)

set(CMAKE_CXX_STANDARD 23)

add_executable(pvz
        main.cpp
        JuegoArchivos/Juego.cpp
        TableroArchivos/Tablero.cpp

        PlantasArchivos/Planta.cpp
        PlantasArchivos/Girasol.cpp
        PlantasArchivos/Cactus.cpp
        PlantasArchivos/CherryBomb.cpp
        PlantasArchivos/PlantaHielo.cpp
        PlantasArchivos/SetaDefensiva.cpp

        ZombiesArchivos/Zombie.cpp
        ZombiesArchivos/ZombieCasco.cpp
        ZombiesArchivos/ZombieCongelado.cpp
        ZombiesArchivos/ZombieRapido.cpp
        ZombiesArchivos/ZombieSaltador.cpp
        ZombiesArchivos/ZombieYeti.cpp
)
