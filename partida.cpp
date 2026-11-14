// DESARROLLADOR C - Flujo de la partida
#include "partida.h"
#include "mazo.h"
#include "tablero.h"
#include "pantallas.h"

void jugarPartida(string& mejorNombre, int& mejorPuntaje)
{
    string nombres[2];
    int puntajes[2] = {0, 0};
    int mazo[TOTAL_CARTAS];
    int cantMazo = 0;
    int tablero[TAM_TABLERO];

    pedirNombres(nombres);
    crearMazo(mazo, cantMazo);
    mezclarMazo(mazo, cantMazo);
    crearTablero(tablero);

    int activo = sortearInicio();
    int resultado = -1;

    while (resultado == -1)
    {
        mostrarEstado(nombres, puntajes, tablero, cantMazo, activo);           // paso 1

        int c1 = robarCarta(mazo, cantMazo);                                   // paso 2
        int c2 = robarCarta(mazo, cantMazo);

        if (esComodin(c1) && esComodin(c2) && cartasEnTablero(tablero) == 0)
        {
            // TODO (C): avisar que pierde el turno y devolver c1 y c2 al mazo
        }
        else
        {
            jugarTurno(nombres, puntajes, tablero, mazo, cantMazo, activo, c1, c2);   // pasos 3, 4 y 5
        }

        mezclarMazo(mazo, cantMazo);                                           // paso 6
        resultado = ganador(puntajes);                                         // paso 7
        if (resultado == -1)
        {
            activo = 1 - activo;                                               // paso 8
        }
    }

    mostrarVictoria(nombres[resultado], puntajes[resultado]);

    // TODO (C): actualizarMejor(...) con los jugadores que correspondan
    //           (confirmar con el docente si cuenta solo el ganador o ambos)
}

void jugarTurno(const string nombres[], int puntajes[],
                int tablero[], int mazo[], int& cantMazo,
                int activo, int c1, int c2)
{
    // TODO (C):
    // 3. Mostrar las dos cartas robadas y pedir cual jugar
    //    (un comodin no se puede elegir si el tablero esta vacio).
    // 4. Segun el tipo de carta, pedir los datos y llamar a la jugada de B.
    //    Si la jugada devuelve false, volver a pedir los datos.
    // 5. Con filaCompleta(): si hay una fila, sumaFila -> puntuarFila (A) ->
    //    mostrar el mensaje segun el resultado -> vaciarFila (B).
    // 6. Devolver al mazo la carta que no se jugo y el comodin si se uso.

    // PROVISORIO: mientras no este armado el turno, las cartas vuelven al mazo
    // para que el arreglo no se quede sin cartas.
    devolverCarta(mazo, cantMazo, c1);
    devolverCarta(mazo, cantMazo, c2);
}
