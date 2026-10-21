#include <iostream>
#include "rlutil.h"
#include "menu.h"

using namespace std;

void dibujarLineaCopada()
{
    for(int x=1; x<=30; x++)
    {
        cout << (char)205;
    }
}

void jugar(){
    int sorteo;
rlutil::cls();//para que al cambiar de pantalla, se limpie lo anterior.
cout << "NUEVA PARTIDA" << endl<< endl;
dibujarLineaCopada(); cout << endl;

string jugadorUno, jugadorDos;
cout << "Ingrese el nombre del primer jugador: " << endl;
cin >> jugadorUno;
cout << "Ingrese el nombre del segundo jugador: " << endl;
cin >> jugadorDos;

rlutil::anykey();
rlutil::cls();
intercambiar(jugadorUno,jugadorDos);
cout << "Comienza: " << jugadorDos << endl;
cout << "jugador uno: " << jugadorUno << endl;
cout << "jugador dos: " << jugadorDos << endl;


}
void intercambiar(string&jugadorUno, string&jugadorDos){
int sorteo = pedirNumeroAleatorio(2);
string aux;
if (sorteo == 2){
aux = jugadorDos;
jugadorDos=jugadorUno;
jugadorUno = aux;

}

}




int pedirNumeroAleatorio(int limite){
int sorteo, comienza;
sorteo = rand()% limite + 1;

return sorteo;

};
