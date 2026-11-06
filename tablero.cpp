// DESARROLLADOR B - Tablero y jugadas
#include "tablero.h"

void crearTablero(vector <int>& tablero)
{
    // TODO (B): dejar el vector con 15 casilleros VACIO
    tablero.clear(); //lo dejo sin posiciones, es decir lo limpio
    for(int i=0; i< FILAS*COLUMNAS;i++)
{//lo recorro y en cada vuelta se le agrega una posicion, hasta q llegue a 15
        tablero.push_back(VACIO);
    }
}

int cartasEnFila(const vector<int>& tablero, int fila)
{
int contadorCartasEnFila = 0;

    for(int i=1; i<=COLUMNAS; i++){
        if(tablero[posicion(fila, i)]!= VACIO){//lo que esta adentro de tablero es el contenido de esa posicion
            contadorCartasEnFila++;
        }
    }
    return contadorCartasEnFila;
}

int cartasEnTablero(const vector<int>& tablero)
{
    // TODO (B)
    int cartasenelTablero=0;
    for (int i=1; i<=FILAS; i++)
        {
            cartasenelTablero+=cartasEnFila(tablero,i);
        }
    return cartasenelTablero;
}

int sumaFila(const vector<int>& tablero, int fila)
{
    // TODO (B): sumar valorCarta() de las cartas de la fila
    int suma = 0;

    for(int i=1; i<=COLUMNAS; i++){
        if(tablero[posicion(fila, i)]!= VACIO){
        suma+=valorCarta(tablero[posicion(fila, i)]);
        }
    }
    return suma;

}

int filaCompleta(const vector<int>& tablero)
{
    // TODO (B): devolver la fila que tiene 5 cartas, o 0 si ninguna
    for (int i=1; i<=FILAS; i++){   //es la constante que tiene 5 como valor, para no poner un numero suelto
        if(cartasEnFila(tablero,i) == COLUMNAS){
            return i;
        }
    }
    return 0;
}

void vaciarFila(vector<int>& tablero, vector<int>& mazo, int fila)
{
    // TODO (B): devolver las cartas de la fila al mazo y dejar la fila vacia
}

bool hayCarta(const vector<int>& tablero, int fila, int col)
{
    // TODO (B)
    if(tablero[posicion(fila,col)]!= VACIO){
    return true;
    }
    return false;
}

bool colocarCarta(vector<int>& tablero, int carta, int fila)
{
    // TODO (B): colocar en un casillero libre de la fila; false si no hay lugar
    for (int i=1; i<=COLUMNAS; i++){//hay q tener cuidado con la inicializacion del i porque si es 0, no es valor valido de la posicion del  vector
        if(tablero[posicion(fila,i)] == VACIO){
            tablero[posicion(fila,i)]= carta;
        return true;
        }
    }
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
    if(tablero[posicion(fila,col)]== VACIO){
        return false;
    }
    mazo.push_back();
    tablero[posicion(fila,col)])=VACIO;
    return true;

}
