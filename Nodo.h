#ifndef NODO_H
#define NODO_H
#include "Figura.h"
typedef Figura Tipo;
class Nodo {
	//atributos
	private:
		Tipo* dato;
		Nodo* siguiente;

	public:
	//metodos
	Nodo(Tipo* dato);
	Tipo* obtener();
	Nodo* obtenerSiguiente();
	void asignarSiguiente(Nodo* punteroNodo);
	void asignarDato(Tipo* dato);
};

#endif // NODO_H
