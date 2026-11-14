// ============================================================
// CONTRATO COMPARTIDO - lo escriben los tres juntos.
// Si algo de este archivo cambia, se avisa y se acuerda entre los tres.
// ============================================================
#ifndef CONTRATO_H
#define CONTRATO_H

#include <string>
using namespace std;

// ---------- Constantes del juego ----------
const int FILAS = 3;
const int COLUMNAS = 5;
const int TAM_TABLERO = FILAS * COLUMNAS;   // 15: tamanio del arreglo del tablero
const int META = 50;            // puntos para ganar
const int LIMITE_CRISIS = 40;   // 40 o mas: los puntos son para el rival
const int CIERRE_EXACTO = 30;   // 30 justo: suma 30 y el rival resta 15
const int PENALIDAD = 15;
const int TOTAL_CARTAS = 54;    // tamanio del arreglo del mazo
const int VACIO = 0;            // casillero vacio en el tablero
const int PUNTOS_VICTORIA = 50; // igual que META

// ---------- Resultados posibles de puntuarFila ----------
const int SIN_PUNTOS = 0;
const int EXACTO = 1;
const int COMUN = 2;
const int CRISIS = 3;

// ---------- Representacion de las cartas ----------
// Una carta es un int:
//    1 a 13  -> picas        (1 = As, 11 = J, 12 = Q, 13 = K)
//   14 a 26  -> corazones
//   27 a 39  -> treboles
//   40 a 52  -> diamantes
//   53 y 54  -> comodines
//    0       -> casillero vacio

inline int valorCarta(int c)  { return (c - 1) % 13 + 1; }   // 1 a 13
inline int paloCarta(int c)   { return (c - 1) / 13; }       // 0 picas, 1 corazones, 2 treboles, 3 diamantes
inline bool esComodin(int c)  { return c >= 53; }
inline bool esDiamante(int c) { return c >= 1 && c <= 52 && paloCarta(c) == 3; }

// ---------- Tablero ----------
// El tablero es UN SOLO arreglo int tablero[TAM_TABLERO] (3 filas x 5 columnas).
// Fila (1-3) y columna (1-5) -> posicion en el arreglo (0-14)
inline int posicion(int fila, int col) { return (fila - 1) * COLUMNAS + (col - 1); }

// ---------- Otros datos de la partida ----------
// mazo     : int mazo[TOTAL_CARTAS] con los codigos de las cartas del mazo,
//            mas int cantMazo = cuantas cartas hay en el mazo (las primeras cantMazo posiciones)
// puntajes : int puntajes[2] (jugador 0 y jugador 1)
// nombres  : string nombres[2]

#endif
