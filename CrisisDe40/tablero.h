// DESARROLLADOR B - Tablero y jugadas
// Las jugadas devuelven true si se pudieron hacer y false si no
// (en ese caso NO modifican nada, asi la pantalla puede volver a pedir los datos).
// Ninguna funcion de este modulo imprime ni lee del teclado.
#ifndef TABLERO_H
#define TABLERO_H

#include "contrato.h"

void crearTablero(vector<int>& tablero);                  // 15 casilleros en VACIO
int  cartasEnFila(const vector<int>& tablero, int fila);
int  cartasEnTablero(const vector<int>& tablero);
int  sumaFila(const vector<int>& tablero, int fila);
int  filaCompleta(const vector<int>& tablero);            // nro de fila (1-3) con 5 cartas, o 0 si ninguna
void vaciarFila(vector<int>& tablero, vector<int>& mazo, int fila);   // las cartas vuelven al mazo

bool hayCarta(const vector<int>& tablero, int fila, int col);

bool colocarCarta(vector<int>& tablero, int carta, int fila);
bool reemplazarCarta(vector<int>& tablero, vector<int>& mazo, int carta, int fila, int col);
bool intercambiarCartas(vector<int>& tablero, int f1, int c1, int f2, int c2);
bool moverCarta(vector<int>& tablero, int fOrigen, int cOrigen, int fDestino);
bool retirarCarta(vector<int>& tablero, vector<int>& mazo, int fila, int col);

#endif
