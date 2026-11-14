// DESARROLLADOR B - Tablero y jugadas
#include "tablero.h"

void crearTablero(int tablero[])
{
    for (int i = 0; i < TAM_TABLERO; i++)
    {
        tablero[i] = VACIO;
    }
}

int cartasEnFila(const int tablero[], int fila)
{
    int contadorCartasEnFila = 0;

    for (int i = 1; i <= COLUMNAS; i++)
    {
        if (tablero[posicion(fila, i)] != VACIO)   // lo que esta adentro del tablero es el contenido de esa posicion
        {
            contadorCartasEnFila++;
        }
    }
    return contadorCartasEnFila;
}

int cartasEnTablero(const int tablero[])
{
    int cartasenelTablero = 0;
    for (int i = 1; i <= FILAS; i++)
    {
        cartasenelTablero += cartasEnFila(tablero, i);
    }
    return cartasenelTablero;
}

int sumaFila(const int tablero[], int fila)
{
    int suma = 0;

    for (int i = 1; i <= COLUMNAS; i++)
    {
        if (tablero[posicion(fila, i)] != VACIO)
        {
            suma += valorCarta(tablero[posicion(fila, i)]);
        }
    }
    return suma;
}

int filaCompleta(const int tablero[])
{
    for (int i = 1; i <= FILAS; i++)
    {
        if (cartasEnFila(tablero, i) == COLUMNAS)   // COLUMNAS vale 5: casilleros por fila
        {
            return i;
        }
    }
    return 0;
}

void vaciarFila(int tablero[], int mazo[], int& cantMazo, int fila)
{
    for (int i = 1; i <= COLUMNAS; i++)
    {
        retirarCarta(tablero, mazo, cantMazo, fila, i);
    }
}

bool hayCarta(const int tablero[], int fila, int col)
{
    if (tablero[posicion(fila, col)] != VACIO)
    {
        return true;
    }
    return false;
}

bool colocarCarta(int tablero[], int carta, int fila)
{
    for (int i = 1; i <= COLUMNAS; i++)   // cuidado: si i empieza en 0 no es una columna valida
    {
        if (tablero[posicion(fila, i)] == VACIO)
        {
            tablero[posicion(fila, i)] = carta;
            return true;
        }
    }
    return false;
}

bool reemplazarCarta(int tablero[], int mazo[], int& cantMazo, int carta, int fila, int col)
{
    if (retirarCarta(tablero, mazo, cantMazo, fila, col) == false)
    {
        return false;
    }
    tablero[posicion(fila, col)] = carta;
    return true;
}

bool intercambiarCartas(int tablero[], int f1, int c1, int f2, int c2)
{
    int auxiliar;
    if (hayCarta(tablero, f1, c1) == false || hayCarta(tablero, f2, c2) == false)
    {
        return false;
    }
    auxiliar = tablero[posicion(f2, c2)];
    tablero[posicion(f2, c2)] = tablero[posicion(f1, c1)];
    tablero[posicion(f1, c1)] = auxiliar;
    return true;
}

bool moverCarta(int tablero[], int fOrigen, int cOrigen, int fDestino)
{
    if (hayCarta(tablero, fOrigen, cOrigen) == false)
    {
        return false;
    }
    if (fDestino == fOrigen)
    {
        return false;
    }
    if (colocarCarta(tablero, tablero[posicion(fOrigen, cOrigen)], fDestino) == false)
    {
        return false;
    }
    tablero[posicion(fOrigen, cOrigen)] = VACIO;
    return true;
}

bool retirarCarta(int tablero[], int mazo[], int& cantMazo, int fila, int col)
{
    if (tablero[posicion(fila, col)] == VACIO)
    {
        return false;
    }
    mazo[cantMazo] = tablero[posicion(fila, col)];   // la carta vuelve al mazo
    cantMazo++;
    tablero[posicion(fila, col)] = VACIO;
    return true;
}
