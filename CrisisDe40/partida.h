// DESARROLLADOR C - Flujo de la partida (une los modulos de A, B y C)
#ifndef PARTIDA_H
#define PARTIDA_H

#include "contrato.h"

void jugarPartida(string& mejorNombre, int& mejorPuntaje);

void jugarTurno(const vector<string>& nombres, vector<int>& puntajes,
                vector<int>& tablero, vector<int>& mazo,
                int activo, int c1, int c2);

#endif
