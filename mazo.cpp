// DESARROLLADOR A - Mazo, puntaje y estadisticas
#include <cstdlib>
#include "mazo.h"

void crearMazo(int mazo[], int& cantMazo)
{
    cantMazo = 0;
    for (int carta = 1; carta <= TOTAL_CARTAS; carta++)
    {
        mazo[cantMazo] = carta;
        cantMazo++;
    }
}

void mezclarMazo(int mazo[], int cantMazo)   // Fisher-Yates
{
    for (int i = cantMazo - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int aux = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = aux;
    }
}

int robarCarta(int mazo[], int& cantMazo)
{
    cantMazo--;
    return mazo[cantMazo];
}

void devolverCarta(int mazo[], int& cantMazo, int carta)
{
    mazo[cantMazo] = carta;
    cantMazo++;
}

int puntuarFila(int suma, int jugador, int puntajes[])
{
    int rival = 1 - jugador;

    if (suma < CIERRE_EXACTO)
    {
        return SIN_PUNTOS;
    }
    if (suma == CIERRE_EXACTO)
    {
        puntajes[jugador] += CIERRE_EXACTO;
        puntajes[rival] -= PENALIDAD;
        if (puntajes[rival] < 0)
        {
            puntajes[rival] = 0;
        }
        return EXACTO;
    }
    if (suma < LIMITE_CRISIS)
    {
        puntajes[jugador] += suma;
        return COMUN;
    }
    puntajes[rival] += suma;     // crisis de los 40: los puntos son para el rival
    return CRISIS;
}

int ganador(const int puntajes[])
{
    if (puntajes[0] >= META)
    {
        return 0;
    }
    if (puntajes[1] >= META)
    {
        return 1;
    }
    return -1;
}

void actualizarMejor(const string& nombre, int puntaje,
                     string& mejorNombre, int& mejorPuntaje)
{
    if (puntaje > mejorPuntaje)
    {
        mejorPuntaje = puntaje;
        mejorNombre = nombre;
    }
}
