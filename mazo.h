#pragma once
#ifndef MAZO_H
#define MAZO_H
#include "contrato.h"
#include <vector>

// ===================== CONSTANTES =====================
const int CANT_CARTAS     = 54;  // 52 de poker + 2 comodines
//const int FILAS           = 3;



// ===================== TIPOS =====================
enum Palo { PICAS, CORAZONES, TREBOLES, DIAMANTES, SIN_PALO };

struct Carta {
    int  valor;      // 1 a 13 (A=1, J=11, Q=12, K=13). El comodin vale 0
    Palo palo;       // SIN_PALO para el comodin
    bool esComodin;
};

struct Mazo {
    std::vector<Carta> cartas;   // el tamanio del vector ES la cantidad de cartas del mazo
};

struct Tablero {
    std::vector< std::vector<Carta> > COLUMNAS;  // [FILAS][CASILLEROS]
    std::vector< std::vector<bool> >  ocupado;     // true si el casillero tiene carta
};

// Resultado de completar una fila. Son CAMBIOS de puntaje (pueden ser negativos).
struct ResultadoFila {
    int suma;              // suma de las 5 cartas
    int deltaCompletador;  // lo que cambia el puntaje de quien completo la fila
    int deltaRival;        // lo que cambia el puntaje del rival (+suma en crisis, -15 en 30 exacto)
};

// ===================== CARTAS Y MAZO =====================
Carta crearCarta(int valor, Palo palo, bool esComodin);
void  inicializarMazo(Mazo &m);               // crea las 54 cartas
void  mezclarMazo(Mazo &m);                   // llamar srand(time(NULL)) UNA vez en main
void  robarDos(Mazo &m, Carta &a, Carta &b);  // saca 2 cartas del mazo
void  devolverCarta(Mazo &m, Carta c);        // vuelve una carta al mazo
int   cantidadMazo(const Mazo &m);            // cuantas cartas hay en el mazo

// ===================== TABLERO =====================
// Todas las filas/casilleros son 0-based (fila 0 = "Fila 1" en pantalla).
void inicializarTablero(Tablero &t);
int  cartasEnFila(const Tablero &t, int fila);
int  sumaFila(const Tablero &t, int fila);
bool filaCompleta(const Tablero &t, int fila);   // true si tiene 5 cartas
bool tableroVacio(const Tablero &t);
void vaciarFila(Tablero &t, Mazo &m, int fila);  // las cartas vuelven al mazo

// ===================== PUNTAJE =====================
ResultadoFila resolverFila(Tablero &t, Mazo &m, int fila); // calcula y vacia la fila
void aplicarPuntos(int &puntaje, int delta);               // suma delta, piso en 0
bool hayGanador(int puntaje);                              // puntaje >= 50

#endif
