#include <cstdlib>
#include <vector>


// ---------- CARTAS Y MAZO ----------
void Carta crearCarta(int valor, Palo palo, bool esComodin) {
    Carta c;
    c.valor = valor;
    c.palo = palo;
    c.esComodin = esComodin;
    return c;
}

void inicializarMazo(Mazo &m) {
    m.cartas.clear();
    for (int p = 0; p < 4; p++) {
        for (int v = 1; v <= 13; v++) {
            m.cartas.push_back(crearCarta(v, (Palo)p, false));
        }
    }
    m.cartas.push_back(crearCarta(0, SIN_PALO, true));
    m.cartas.push_back(crearCarta(0, SIN_PALO, true));
}

void mezclarMazo(Mazo &m) {  // Fisher-Yates
    for (int i = (int)m.cartas.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta aux = m.cartas[i];
        m.cartas[i] = m.cartas[j];
        m.cartas[j] = aux;
    }
}

void robarDos(Mazo &m, Carta &a, Carta &b) {
    a = m.cartas.back();
    m.cartas.pop_back();
    b = m.cartas.back();
    m.cartas.pop_back();
}

void devolverCarta(Mazo &m, Carta c) {
    m.cartas.push_back(c);
}

int cantidadMazo(const Mazo &m) {
    return (int)m.cartas.size();
}

// ---------- TABLERO ----------
void inicializarTablero(Tablero &t) {
    Carta vacia = crearCarta(0, SIN_PALO, false);
    t.casilleros = std::vector< std::vector<Carta> >(FILAS, std::vector<Carta>(CASILLEROS, vacia));
    t.ocupado    = std::vector< std::vector<bool> >(FILAS, std::vector<bool>(CASILLEROS, false));
}

int cartasEnFila(const Tablero &t, int fila) {
    int n = 0;
    for (int c = 0; c < CASILLEROS; c++)
        if (t.ocupado[fila][c]) n++;
    return n;
}

int sumaFila(const Tablero &t, int fila) {
    int suma = 0;
    for (int c = 0; c < CASILLEROS; c++)
        if (t.ocupado[fila][c]) suma += t.casilleros[fila][c].valor;
    return suma;
}

bool filaCompleta(const Tablero &t, int fila) {
    return cartasEnFila(t, fila) == CASILLEROS;
}

bool tableroVacio(const Tablero &t) {
    for (int f = 0; f < FILAS; f++)
        if (cartasEnFila(t, f) > 0) return false;
    return true;
}

void vaciarFila(Tablero &t, Mazo &m, int fila) {
    for (int c = 0; c < CASILLEROS; c++) {
        if (t.ocupado[fila][c]) {
            devolverCarta(m, t.casilleros[fila][c]);
            t.ocupado[fila][c] = false;
        }
    }
}

// ---------- PUNTAJE ----------
ResultadoFila resolverFila(Tablero &t, Mazo &m, int fila) {
    ResultadoFila r;
    r.suma = sumaFila(t, fila);
    r.deltaCompletador = 0;
    r.deltaRival = 0;

    if (r.suma < 30) {
        // nadie suma
    } else if (r.suma == 30) {
        r.deltaCompletador = 30;
        r.deltaRival = -15;
    } else if (r.suma <= 39) {
        r.deltaCompletador = r.suma;
    } else {  // 40 o mas: crisis de los 40
        r.deltaRival = r.suma;
    }

    vaciarFila(t, m, fila);
    return r;
}

void aplicarPuntos(int &puntaje, int delta) {
    puntaje += delta;
    if (puntaje < 0) puntaje = 0;
}

bool hayGanador(int puntaje) {
    return puntaje >= PUNTOS_VICTORIA;
}
