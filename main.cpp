// DESARROLLADOR C - Programa principal y menu
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "contrato.h"
#include "pantallas.h"
#include "partida.h"
#include "mazo.h"
using namespace std;

int main()
{
    srand(time(NULL));          // una sola vez en todo el programa

    string mejorNombre = "";    // estadisticas: solo en memoria
    int mejorPuntaje = 0;
    int opcion;

    do
    {
        limpiarPantalla();
        mostrarMenu();
        opcion = leerEntero(0, 3);

        if (opcion == 1)
        {
            jugarPartida(mejorNombre, mejorPuntaje);
        }
        else if (opcion == 2)
        {
            mostrarEstadisticas(mejorNombre, mejorPuntaje);
        }
        else if (opcion == 3)
        {
            mostrarReglas();
        }
    } while (opcion != 0);

    return 0;
}
