=============================================================================
                               PLANTAS VS ZOMBIES
=============================================================================

[ DESCRIPCIÓN ]
Este proyecto es una implementación del clásico juego de estrategia "Plantas vs.
Zombies" desarrollado en C++ utilizando Programación Orientada a Objetos (POO).
El jugador debe defender su casa de oleadas de zombis colocando estratégicamente
diferentes tipos de plantas en un tablero de 5 filas por 9 columnas.

El juego cuenta con un sistema de turnos, gestión de recursos (soles),
habilidades especiales, y persistencia de datos (guardar y cargar partidas).

[ MECÁNICAS DEL JUEGO ]
El juego se desarrolla por turnos. En cada turno ocurren eventos en el siguiente orden:
1. Las plantas activan sus habilidades (generar soles, ataques especiales, etc.).
2. El jugador realiza su acción (Colocar planta, Remover planta, Guardar, etc.).
3. Los zombis avanzan o atacan si tienen una planta enfrente.

Objetivo:
- VICTORIA: Sobrevivir a todas las oleadas de zombis (Nivel 10 por defecto).
- DERROTA: Si un zombi logra cruzar la última columna (llega a la casa).

[ CONTROLES ]
El juego se maneja mediante menús numéricos en la consola.
- Coordenadas:
  - Filas: 1 a 5
  - Columnas: 1 a 9

[ CONTENIDO ]

--- PLANTAS ---
1. Girasol (50 Soles):
   - Genera soles cada 2 turnos.
   - Habilidad Especial: "Rayo Solar" (Daña a toda la fila cada 5 turnos).
2. Seta Defensiva (50 Soles):
   - Tanque defensivo con alta vida.
   - Recupera salud pasivamente.
3. Cactus (100 Soles):
   - Atacante a distancia estándar.
   - Pasiva: Daña a los zombis que lo tocan (espinas).
4. Planta Hielo (175 Soles):
   - Pasiva: Ralentiza a los zombis en su misma fila.
   - Habilidad Especial: "Ventisca" (Congela a TODOS los zombis del tablero cada 4 turnos).
5. CherryBomb (150 Soles):
   - Explota instantáneamente al ser colocada.
   - Elimina a los zombis en un área de 3x3 alrededor.

--- ZOMBIS ---
1. Zombi Rápido (Velocidad Alta):
   - Poca vida pero avanza muy rápido.
   - Habilidad: Acumula velocidad y puede avanzar varias casillas de golpe.
2. Zombi con Casco (Tanque):
   - Muy lento pero extremadamente resistente.
   - Habilidad: "Autodestrucción" (Explota al tocar una planta para destruirla).
3. Zombi Saltador (Técnico):
   - Usa una pértiga para saltar la primera planta que encuentra.
4. Zombi Congelado (Resistente):
   - Inmune a los efectos de ralentización y congelación de la Planta Hielo.
5. Zombi Yeti (Jefe):
   - Gran cantidad de vida y daño alto.
   - Habilidad: Realiza un ataque doble cada 3 golpes.

[ SISTEMA DE GUARDADO ]
El juego permite guardar el progreso actual (Soles, Oleada, Puntos) en un archivo
de texto.
- Para guardar: Seleccione la opción "Guardar Partida" dentro del juego e ingrese un nombre (ej. partida1.txt).
- Para cargar: Seleccione "Cargar Partida" en el menú principal e ingrese el nombre del archivo.

=============================================================================