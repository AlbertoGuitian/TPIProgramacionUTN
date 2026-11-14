// DESARROLLADOR C - Pantallas y lectura del teclado
#include <iostream>
#include <cstdlib>
#include "pantallas.h"
#include "tablero.h"    // C usa cartasEnFila y sumaFila para dibujar el tablero
using namespace std;

void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar()
{
#ifdef _WIN32
    cout << "Presione una tecla para continuar...";
    system("pause > nul");
    cout << endl;
#else
    cout << "Presione ENTER para continuar...";
    cin.ignore(10000, '\n');
    cin.get();
#endif
}

void mostrarMenu()
{
    cout << "==============================" << endl;
    cout << " CRISIS DE LOS 40" << endl;
    cout << "==============================" << endl;
    cout << " 1 - JUGAR" << endl;
    cout << " 2 - ESTADISTICAS" << endl;
    cout << " 3 - REGLAS DEL JUEGO" << endl;
    cout << "------------------------------" << endl;
    cout << " 0 - SALIR" << endl;
    cout << "==============================" << endl;
    cout << "Opcion: ";
}

int leerEntero(int minimo, int maximo)
{
    int n;
    cin >> n;
    while (cin.fail() || n < minimo || n > maximo)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "Valor invalido. Ingrese un numero entre " << minimo << " y " << maximo << ": ";
        cin >> n;
    }
    return n;
}


    // TODO (C): resumen del reglamento (valor de las cartas, turno, cartas especiales,
    //           puntaje de una fila completada y condiciones de fin de partida)
void mostrarReglas()
{
    cout << "========== REGLAS DEL JUEGO ==========" << endl;

    cout << "El juego es para dos jugadores." << endl;
    cout << "El tablero tiene 3 filas y 5 columnas." << endl;
    cout << "Cada fila puede tener hasta 5 cartas." << endl;

    cout << endl;
    cout << "Las cartas tienen valores del 1 al 13." << endl;
    cout << "Existen 2 comodines." << endl;

    cout << endl;
    cout << "La meta es alcanzar 50 puntos." << endl;
    cout << "Si una fila suma exactamente 30 puntos," << endl;
    cout << "el rival recibe una penalidad de 15 puntos." << endl;

    cout << "Si una fila suma 40 puntos o mas," << endl;
    cout << "los puntos corresponden al rival." << endl;

    cout << "======================================" << endl;

    pausar();
}

void mostrarEstadisticas(const string& mejorNombre, int mejorPuntaje)
{
    cout << "==================================" << endl;
    cout << "          ESTADISTICAS" << endl;
    cout << "==================================" << endl;

    if (mejorNombre == "" || mejorPuntaje <= 0)
    {
        cout << "Todavia no hay partidas registradas." << endl;
    }
    else
    {
        cout << "Mejor jugador: " << mejorNombre << endl;
        cout << "Mejor puntaje: " << mejorPuntaje << endl;
    }

    cout << "==================================" << endl;

    pausar();
}

// TODO (C): pantalla NUEVA PARTIDA: pedir nombre del jugador 1 y del jugador 2
//Qué hace nombres.resize(2)? Reserva dos posiciones en el vector: una para cada jugador.
void pedirNombres(string nombres[])
{
    cout << "==================================" << endl;
    cout << "          NUEVA PARTIDA" << endl;
    cout << "==================================" << endl;

    cout << "Ingrese el nombre del jugador 1: ";
    cin >> ws;
    getline(cin, nombres[0]);

    cout << "Ingrese el nombre del jugador 2: ";
    getline(cin, nombres[1]);
}


// TODO (C): devolver 0 o 1 al azar y mostrar "Sorteo: empieza ..."
int sortearInicio()
{
    int inicio;

    inicio = rand() % 2;

    cout << endl;
    cout << "==================================" << endl;
    cout << "              SORTEO" << endl;
    cout << "==================================" << endl;

    cout << "Empieza el jugador " << inicio + 1 << endl;

    cout << "==================================" << endl;

    return inicio;
}

    void mostrarEstado(const string nombres[], const int puntajes[],
                   const int tablero[], int cartasMazo, int activo)
    // TODO (C): encabezado, puntajes (marcar con > al jugador activo),
    //           tablero con cartas por fila y suma de cada fila
{
    cout << "==================================" << endl;
    cout << "          CRISIS DE LOS 40" << endl;
    cout << "==================================" << endl;

    cout << "CARTAS EN EL MAZO: " << cartasMazo << endl;

    cout << endl;
    cout << "PUNTAJES:" << endl;


    for (int i = 0; i < 2; i++)
    {
        if (i == activo)
        {
            cout << "> ";
        }
        else
        {
            cout << "  ";
        }

        cout << nombres[i] << ": " << puntajes[i] << " puntos" << endl;
    }

    cout << endl;
    cout << "TABLERO:" << endl;

    for (int fila = 1; fila <= FILAS; fila++)
    {
        cout << "Fila " << fila << ": ";

        for (int col = 1; col <= COLUMNAS; col++)
        {
            int carta = tablero[posicion(fila, col)];

            cout << "[" << textoCarta(carta) << "] ";
        }

        cout << endl;

        cout << "Cartas: " << cartasEnFila(tablero, fila);
        cout << "/" << COLUMNAS;

        cout << " | Suma: " << sumaFila(tablero, fila);

        cout << endl;
    }

    cout << "==================================" << endl;
}

string textoCarta(int carta)
// TODO (C): valor + inicial del palo (P, C, T, D) o "COMODIN"
{
    if (carta == VACIO)
    {
        return "   ";
    }

    if (esComodin(carta))
    {
        return "COMODIN";
    }

    if (carta < 1 || carta > 52)
    {
        return "ERROR";
    }

    int valor = valorCarta(carta);
    int palo = paloCarta(carta);

    string textoValor;

    if (valor == 1)
    {
        textoValor = "A";
    }
    else if (valor == 11)
    {
        textoValor = "J";
    }
    else if (valor == 12)
    {
        textoValor = "Q";
    }
    else if (valor == 13)
    {
        textoValor = "K";
    }
    else
    {
        textoValor = to_string(valor);
    }

    string textoPalo;

    if (palo == 0)
    {
        textoPalo = "P";
    }
    else if (palo == 1)
    {
        textoPalo = "C";
    }
    else if (palo == 2)
    {
        textoPalo = "T";
    }
    else
    {
        textoPalo = "D";
    }

    if (textoValor.length() == 1)
    {
        textoValor = " " + textoValor;
    }

    return textoValor + " " + textoPalo;
}

void mostrarVictoria(const string& nombre, int puntaje)
{
    cout << endl;
    cout << "==================================" << endl;
    cout << "           FIN DEL JUEGO" << endl;
    cout << "==================================" << endl;

    cout << "FELICITACIONES " << nombre << "!" << endl;
    cout << "GANASTE LA PARTIDA." << endl;
    cout << "Puntaje final: " << puntaje << endl;

    cout << "==================================" << endl;

    pausar();
}
