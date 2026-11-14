// DESARROLLADOR C - Pantallas y lectura del teclado
// Es el unico modulo que imprime y lee datos.
#ifndef PANTALLAS_H
#define PANTALLAS_H

#include "contrato.h"

void limpiarPantalla();
void pausar();                                   // "Presione una tecla para continuar..."
void mostrarMenu();
int  leerEntero(int minimo, int maximo);         // repite hasta que el numero este en rango

void mostrarReglas();
void mostrarEstadisticas(const string& mejorNombre, int mejorPuntaje);
void pedirNombres(string nombres[]);
int  sortearInicio();                            // 0 o 1
void mostrarEstado(const string nombres[], const int puntajes[],
                   const int tablero[], int cartasMazo, int activo);
string textoCarta(int carta);                    // ej: " 7 P", "10 D", "COMODIN"
void mostrarVictoria(const string& nombre, int puntaje);

#endif
