// DESARROLLADOR A - Mazo, puntaje y estadisticas
#include <cstdlib>
#include "mazo.h"

void crearMazo(vector<int>& mazo)
{
    // TODO (A): cargar las 54 cartas
}


void mezclarMazo(vector<int>& mazo)
{
    // TODO (A): mezclar usando rand() (srand ya se llama en main)
}

int robarCarta(vector<int>& mazo)
{
    // TODO (A): sacar y devolver la carta de arriba
    return 0;
}

void devolverCarta(vector<int>& mazo, int carta)
{
    // TODO (A): volver a poner la carta en el mazo
}

int puntuarFila(int suma, int jugador, vector<int>& puntajes)
{
    // TODO (A): tabla de puntaje (menor a 30, 30 exacto, 31 a 39, 40 o mas)
    return SIN_PUNTOS;
}

int ganador(const vector<int>& puntajes)
{
    // TODO (A): devolver -1 si nadie llego a META, sino el indice del ganador
    // PROVISORIO: devuelve 0 para que la partida de prueba no quede en bucle infinito.
    return 0;
}

void actualizarMejor(const string& nombre, int puntaje,
                     string& mejorNombre, int& mejorPuntaje)
{
    // TODO (A): si puntaje supera al mejor guardado, actualizar nombre y puntaje
}
