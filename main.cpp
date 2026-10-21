#include <iostream>
#include "rlutil.h"
#include "menu.h"
#include <cstdlib> ///srand() y rand()
#include <ctime>  ///time()

using namespace std;
int main()

{
srand(time(0));
int opcion;


do{

dibujarLineaCopada(); cout << endl<< endl;
cout << "     CRISIS DE LOS 40       "<< endl<< endl;
dibujarLineaCopada(); cout << endl<< endl;

 cout << " OPCION 1 " << endl;
 cout << " OPCION 2 " << endl;
 cout << " OPCION 3 " << endl;
 cout << "----------" << std::endl;
 cout << "   SALIR  " << endl<< endl;
 cout << "Opcion: " ;
 cin >> opcion;

switch (opcion) {
           /// jugarPartida(); seria la funcion para jugar la partida -
            case 1:
                jugar();
                break;
            case 2:///    mostrarEstadisticas(); mostrar

                break;
            case 3: ///    mostrarReglas();

                break;
            case 0:
                cout << "Gracias por jugar a Crisis de los 40! Hasta luego." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, elija una opcion correcta."<< endl;

}

    } while (opcion != 0);


 return 0;
    }
