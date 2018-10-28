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

	//constructor
	//pre: recibe un puntero a un dato
	//post: construye el nodo
	Nodo(Tipo* dato);

	//pre: -
	//post: devuelve el dato del nodo
	Tipo* obtener();

	//pre: -
	//post: devuelve el siguiente nodo
	Nodo* obtenerSiguiente();

	//pre: recibe un puntero a nodo
	//post: asigna ese puntero a nodo al siguiente
	void asignarSiguiente(Nodo* punteroNodo);

	void asignarDato(Tipo* dato);

	//destructor
	~Nodo();
};

#endif // NODO_H
