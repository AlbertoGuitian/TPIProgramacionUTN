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

void mostrarReglas()
{
    // TODO (C): resumen del reglamento (valor de las cartas, turno, cartas especiales,
    //           puntaje de una fila completada y condiciones de fin de partida)
    cout << "[pendiente: reglas del juego]" << endl;
    pausar();
}

void mostrarEstadisticas(const string& mejorNombre, int mejorPuntaje)
{
    // TODO (C): mostrar el formato de la pantalla ESTADISTICAS del PDF
    cout << "[pendiente: estadisticas]" << endl;
    pausar();
}

void pedirNombres(vector<string>& nombres)
{
    // TODO (C): pantalla NUEVA PARTIDA: pedir nombre del jugador 1 y del jugador 2
    cout << "[pendiente: pedir nombres]" << endl;
}

int sortearInicio()
{
    // TODO (C): devolver 0 o 1 al azar y mostrar "Sorteo: empieza ..."
    return 0;
}

void mostrarEstado(const vector<string>& nombres, const vector<int>& puntajes,
                   const vector<int>& tablero, int cartasMazo, int activo)
{
    // TODO (C): encabezado, puntajes (marcar con > al jugador activo),
    //           tablero con cartas por fila y suma de cada fila
    cout << "[pendiente: mostrar estado]" << endl;
}

string textoCarta(int carta)
{
    // TODO (C): valor + inicial del palo (P, C, T, D) o "COMODIN"
    return "";
}

void mostrarVictoria(const string& nombre, int puntaje)
{
    // TODO (C): pantalla de victoria
    cout << "[pendiente: pantalla de victoria]" << endl;
    pausar();
}
