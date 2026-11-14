// DESARROLLADOR A - Mazo, puntaje y estadisticas
#ifndef MAZO_H
#define MAZO_H

#include "contrato.h"

void crearMazo(int mazo[], int& cantMazo);                  // carga las cartas 1..54
void mezclarMazo(int mazo[], int cantMazo);
int  robarCarta(int mazo[], int& cantMazo);                 // saca la carta de arriba y la devuelve
void devolverCarta(int mazo[], int& cantMazo, int carta);

// jugador = quien completo la fila (0 o 1). Devuelve SIN_PUNTOS, EXACTO, COMUN o CRISIS.
int  puntuarFila(int suma, int jugador, int puntajes[]);

int  ganador(const int puntajes[]);                         // -1 si nadie llego a META, sino 0 o 1

void actualizarMejor(const string& nombre, int puntaje,
                     string& mejorNombre, int& mejorPuntaje);

#endif
