// DESARROLLADOR B - Tablero y jugadas
// Las jugadas devuelven true si se pudieron hacer y false si no
// (en ese caso NO modifican nada, asi la pantalla puede volver a pedir los datos).
// Ninguna funcion de este modulo imprime ni lee del teclado.
#ifndef TABLERO_H
#define TABLERO_H

#include "contrato.h"

void crearTablero(int tablero[]);                          // TAM_TABLERO casilleros en VACIO
int  cartasEnFila(const int tablero[], int fila);
int  cartasEnTablero(const int tablero[]);
int  sumaFila(const int tablero[], int fila);
int  filaCompleta(const int tablero[]);                    // nro de fila (1-3) con 5 cartas, o 0 si ninguna
void vaciarFila(int tablero[], int mazo[], int& cantMazo, int fila);   // las cartas vuelven al mazo

bool hayCarta(const int tablero[], int fila, int col);

bool colocarCarta(int tablero[], int carta, int fila);
bool reemplazarCarta(int tablero[], int mazo[], int& cantMazo, int carta, int fila, int col);
bool intercambiarCartas(int tablero[], int f1, int c1, int f2, int c2);
bool moverCarta(int tablero[], int fOrigen, int cOrigen, int fDestino);
bool retirarCarta(int tablero[], int mazo[], int& cantMazo, int fila, int col);

#endif
