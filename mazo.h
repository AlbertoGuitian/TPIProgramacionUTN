// DESARROLLADOR A - Mazo, puntaje y estadisticas
#ifndef MAZO_H
#define MAZO_H

#include "contrato.h"

void crearMazo(vector<int>& mazo);               // carga las cartas 1..54
void mezclarMazo(vector<int>& mazo);
int  robarCarta(vector<int>& mazo);              // saca la carta de arriba y la devuelve
void devolverCarta(vector<int>& mazo, int carta);

// Aplica la tabla de puntaje de una fila completada.
// jugador = quien la completo (0 o 1). Modifica puntajes (el puntaje nunca baja de 0).
// Devuelve SIN_PUNTOS, EXACTO, COMUN o CRISIS.
int  puntuarFila(int suma, int jugador, vector<int>& puntajes);

int  ganador(const vector<int>& puntajes);       // -1 si nadie llego a META, sino 0 o 1

void actualizarMejor(const string& nombre, int puntaje,
                     string& mejorNombre, int& mejorPuntaje);

#endif
