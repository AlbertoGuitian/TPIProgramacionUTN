// DESARROLLADOR B - Tablero y jugadas
#include "tablero.h"

void crearTablero(vector<int>& tablero)
{
    // TODO (B): dejar el vector con 15 casilleros VACIO
}

int cartasEnFila(const vector<int>& tablero, int fila)
{
    // TODO (B)
    return 0;
}

int cartasEnTablero(const vector<int>& tablero)
{
    // TODO (B)
    return 0;
}

int sumaFila(const vector<int>& tablero, int fila)
{
    // TODO (B): sumar valorCarta() de las cartas de la fila
    return 0;
}

int filaCompleta(const vector<int>& tablero)
{
    // TODO (B): devolver la fila que tiene 5 cartas, o 0 si ninguna
    return 0;
}

void vaciarFila(vector<int>& tablero, vector<int>& mazo, int fila)
{
    // TODO (B): devolver las cartas de la fila al mazo y dejar la fila vacia
}

bool hayCarta(const vector<int>& tablero, int fila, int col)
{
    // TODO (B)
    return false;
}

bool colocarCarta(vector<int>& tablero, int carta, int fila)
{
    // TODO (B): colocar en un casillero libre de la fila; false si no hay lugar
    return false;
}

bool reemplazarCarta(vector<int>& tablero, vector<int>& mazo, int carta, int fila, int col)
{
    // TODO (B): la carta reemplazada vuelve al mazo; false si el casillero esta vacio
    return false;
}

bool intercambiarCartas(vector<int>& tablero, int f1, int c1, int f2, int c2)
{
    // TODO (B): ambos casilleros deben tener carta
    return false;
}

bool moverCarta(vector<int>& tablero, int fOrigen, int cOrigen, int fDestino)
{
    // TODO (B): mover a un casillero libre de otra fila; false si no se puede
    return false;
}

bool retirarCarta(vector<int>& tablero, vector<int>& mazo, int fila, int col)
{
    // TODO (B): la carta retirada vuelve al mazo; false si el casillero esta vacio
    return false;
}
