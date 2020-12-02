#include <iostream>
using namespace std;
#define CantidadIngresos 6
#define Tope 8

void Incializar(int vectorConectividad[Tope]);

void Conectar(int vectorConectividad[Tope], int p, int q);

bool EstanConectados(int vectorConectividad[Tope], int p, int q);
bool EsRaiz(int vectorConectividad[Tope], int p);
int ObtenerPadre(int vectorConectividad[Tope], int p);
int ObtenerRaiz(int vectorConectividad[Tope], int p);

int main() {
	int p, q;
	int vectorConectividad[Tope];
	Incializar(vectorConectividad);

	// Definir una estructura de datos para cada elemento
	// Llamar a una funcion con esa intancia/variable y poner que todos esten desconectados
	for (int numeroIngreso = 0;
		numeroIngreso < CantidadIngresos;
		++numeroIngreso)
	{
		cin >> p;
		cin >> q;
		// TODO: Si p y q estan conectados mostrar -
		// TODO: Si p y q no estan conectados conectarlos y mostrarlos
		cout << p << "-" << q << endl;
	}

	return 0;
}

// O(N)
void Incializar(int vectorConectividad[Tope]) {
	for (int i = 0; i < Tope; i++) {
		vectorConectividad[i] = i;
	}
}

//
void Conectar(int vectorConectividad[Tope], int p, int q) {
	vectorConectividad[p] = ObtenerRaiz(vectorConectividad, q);
}

// O(1)
bool EstanConectados(int vectorConectividad[Tope], int p, int q) {
	bool estanConectados = ObtenerRaiz(vectorConectividad, p) == ObtenerRaiz(vectorConectividad, q);
	return estanConectados;
}


bool EsRaiz(int vectorConectividad[Tope], int p) {
	bool esRaiz = ObtenerPadre(vectorConectividad, p) == p;
	return esRaiz;
}

int ObtenerPadre(int vectorConectividad[Tope], int p) {
	return vectorConectividad[p];
}

// O(Log(N) -> h)
int ObtenerRaiz(int vectorConectividad[Tope], int p) {
	int  raiz = p;
	while (!EsRaiz(vectorConectividad, raiz)) {
		raiz = ObtenerPadre(vectorConectividad, raiz);
	}

	return raiz;
}

// Codigo Cliente
// t0: 0 1 2 3 4 5 6 7 [-1 -1 -1 -1 -1 -1 -1]
// t1: 1 2 => 1-2 0 3 4 5 6 7 [0 1 2 0 0 0 0 0]
// 2 3 => 1-2-3 0 4 5 6 7
