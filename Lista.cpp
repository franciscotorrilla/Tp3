#include "Lista.h"

Lista::Lista() {
	primero = 0;
	longitud = 0;
}

Lista::~Lista () {
	while(longitud > 0) {
		borrar(1);
	}
}

bool Lista::listaVacia() {
	return (longitud == 0);
}

void Lista::insertar( Tipo* e, unsigned pos) {

	Nodo* nuevo = new Nodo(e);
	if(pos == 1) {
		nuevo->asignarSiguiente(primero);
		primero = nuevo;
	}
	else {
		Nodo* anterior = obtenerNodo(pos-1);
		nuevo->asignarSiguiente(anterior->obtenerSiguiente());
		anterior->asignarSiguiente(nuevo);
	}
	longitud ++;
}

Nodo* Lista::obtenerNodo(unsigned pos) {

	Nodo* aux = primero;
	for(unsigned i = 1; i < pos; i++) {
		aux = aux->obtenerSiguiente();
	}
	return aux;
}

Tipo* Lista::consultar(unsigned pos) {

	Nodo* aux = obtenerNodo(pos);
	return aux->obtener();
}

void Lista::borrar(unsigned pos) {

	Nodo* borrar = primero;
	if(pos == 1) {
		primero = borrar->obtenerSiguiente();
	}
	else {
		Nodo* anterior = obtenerNodo(pos-1);
		borrar = anterior->obtenerSiguiente();
		anterior->asignarSiguiente(borrar->obtenerSiguiente());
	}
	delete borrar;
	longitud --;
}
