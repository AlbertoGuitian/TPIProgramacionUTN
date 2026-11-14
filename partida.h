// DESARROLLADOR C - Flujo de la partida (une los modulos de A, B y C)
#ifndef PARTIDA_H
#define PARTIDA_H

#include "contrato.h"

void jugarPartida(string& mejorNombre, int& mejorPuntaje);

void jugarTurno(const string nombres[], int puntajes[],
                int tablero[], int mazo[], int& cantMazo,
                int activo, int c1, int c2);

string pedirNombres(string nombres);
void crearMazo(int mazo, int cantMazo);
void mezclarMazo(int mazo, int cantMazo);
void crearTablero(int tablero);






#endif
