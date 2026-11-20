// DESARROLLADOR C - Flujo de la partida
#include "partida.h"
#include "mazo.h"
#include "tablero.h"
#include "pantallas.h"
#include <iostream>
using namespace std;

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
    int cartaElegida, opcionElegida, filaElegida, cartaNoElegida;
    // TODO (C):
    // 3. Mostrar las dos cartas robadas y pedir cual jugar
    //    (un comodin no se puede elegir si el tablero esta vacio).
    do
    {
        cout << "Le toca a: " << nombres[activo] << endl;
        cout << "1) La carta robada es: " << textoCarta(c1) << " y vale: " << valorCarta(c1) << endl;
        cout << "2) La carta robada es: " << textoCarta(c2) << " y vale: " << valorCarta(c2) << endl;
        cout << "Seleccione una carta para jugar (1 o 2): " ;


        opcionElegida = leerEntero(1,2);

    if ( opcionElegida ==1)
        {
        cartaElegida = c1;
        cartaNoElegida = c2;
        }

    else {
        cartaElegida = c2;
        cartaNoElegida = c1;
    }
    }
    while(esComodin(cartaElegida) && cartasEnTablero(tablero)==0);
    // agrego la funcionalidad del diamante.
//    if (esDiamante(cartaElegida)){
//        cout << "1) Colocar - 2) Reemplazar " << endl;
//    }
//    if (leerEntero(1,2) == 1){
//        colocarCarta(tablero, cartaElegida,filaElegida);
//    }
//    //else{
//        //reemplazarCarta()
//    }
//
//    cout << "Ingrese el numero de fila donde colocar la carta (1-3): " << endl;
//
//    filaElegida = leerEntero(1,3);
//
//
//    colocarCarta(tablero,cartaElegida,filaElegida);

    cout << nombres[activo] << " coloca [ " << textoCarta(cartaElegida) << " ] en la fila " << filaElegida << endl;

    // 6. Devolver al mazo la carta que no se jugo y el comodin si se uso.
    devolverCarta(mazo, cantMazo, cartaNoElegida); // devuelve la carta que no se elegió

    // 4. Segun el tipo de carta, pedir los datos y llamar a la jugada de B.
    //    Si la jugada devuelve false, volver a pedir los datos.


    // 5. Con filaCompleta(): si hay una fila completa, sumaFila -> puntuarFila (A) ->
    //    mostrar el mensaje segun el resultado -> vaciarFila (B).
    int sumaParcialFila=0, resultadoFila=0;
    int filaLlena = filaCompleta(tablero);
    if (filaLlena !=0 ){
        sumaParcialFila = sumaFila(tablero, filaLlena);
        resultadoFila = puntuarFila(sumaParcialFila,activo,puntajes);


        if (resultadoFila == EXACTO)
            {
            cout << "30 EXACTOS " << nombres[activo] << " suma 30 puntos y " << nombres [!activo] << " pierde: " << PENALIDAD << " puntos :( " << endl;
            }
             else if(resultadoFila == COMUN)
                {
                cout << nombres[activo] << " suma: " << sumaParcialFila << endl;
                }
             else if(resultadoFila == CRISIS)
                {
                cout << "CRISIS DE LOS 40!! " << nombres[!activo] << " suma: " << sumaParcialFila << endl;
                }
             else
                {
                cout << "Resultado fila menor a 30 puntos, nadie suma." << endl;
                }
            vaciarFila(tablero,mazo,cantMazo,filaLlena);
    }


}
