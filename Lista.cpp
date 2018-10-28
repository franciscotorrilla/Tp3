#include "Lista.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "miniwin.h"
using namespace std;
using namespace miniwin;
int leerNumero() {
    string entrada;
    for(int simbolo = tecla(); simbolo != RETURN; simbolo = tecla()) {
            if((simbolo == ESCAPE || simbolo == 8) && !entrada.empty()) {
                borra();
                entrada.pop_back();
            }
            else if(isdigit(simbolo)) {
                entrada += simbolo;
            }
            texto(10,480,"Eleccion: " + entrada);
            refresca();
            espera(20);
    }
    return atoi(&entrada[0]);
}

int menuMiniwin() {

    int numero;
    texto(10,5,"Ingrese 0 para cerrar el menu");
    texto(10,20,"Ingrese 1 para consultar que objeto hay en determinada posicion.");
    texto(10,35,"Ingrese 2 para dar de baja un objeto en determinada posicion.");
    texto(10,50,"Ingrese 3 para agregar un nuevo objeto de manera manual." );
    texto(10,65,"Ingrese 4 para listar todos los objetos.");
    texto(10,80,"Ingrese 5 para consultar la superficie maxima.");
    texto(10,95,"Ingrese 6 para consultar la superficie minima.");
    texto(10,110,"Ingrese 7 para consultar el perimetro maximo.");
    texto(10,125,"Ingrese 8 para consultar el perimetro minimo.");
    refresca();
    numero = leerNumero()+48;
    return numero;
}
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

void Lista::menu(){

    char i = '1';
    while (i != '0'){
        i = menuMiniwin();
        borra();
		opciones(i);
   	}
    miniwin::vcierra();
    }

void Lista::opciones(char i){

    unsigned pos;
    switch (i){
	case '0':
	    break;
        case '1':
            texto(10,465,"Ingrese la posicion");
            pos = leerNumero();
            cout <<pos;
            if (pos<=longitud)
                consultar(pos)->mostrar();
            else
                texto(5,5,"No hay elemento en dicha posicion");
            break;
        case '2':
            texto(10,465,"Ingrese la posicion");
            pos = leerNumero();
            if (pos<=longitud){
                texto(5,5,"Se ha dado de baja al ");
                consultar(pos)->mostrar();
                borrar(pos);
                }
            else
                texto(5,5,"No hay elemento en dicha posicion.");
            break;
        case '3': agregarFigura();
            break;
        case '4': mostrarListadoFiguras();
            break;
        case '5': consultarSuperficieMaxima();
            break;
        case '6': consultarSuperficieMinima();
            break;
        case '7': consultarPerimetroMaximo();
            break;
        case '8': consultarPerimetroMinimo();
            break;
        default:
            texto(5,5,"Dato ingresado invalido");
        }
        refresca();
        sleep(2);
        borra();
       }

void Lista::consultarSuperficieMaxima(){
    Nodo* nodo = primero;
    double valorMaximo=nodo->obtener()->superficie();
    for (unsigned i=1; i<longitud; i++){
        nodo=nodo->obtenerSiguiente();
        if (nodo->obtener()->superficie()>valorMaximo)
            valorMaximo = nodo->obtener()->superficie();
        }
    texto(10,10, "La superficie maxima es de: " + to_string(valorMaximo));
}

void Lista::consultarSuperficieMinima(){
    Nodo* nodo = primero;
    double valorMinimo=nodo->obtener()->superficie();
    for (unsigned i=1; i<longitud; i++){
        nodo=nodo->obtenerSiguiente();
        if (nodo->obtener()->superficie() < valorMinimo)
            valorMinimo = nodo->obtener()->superficie();
        }
    texto(10,10, "La superficie minima es de: " + to_string(valorMinimo));
}

void Lista::consultarPerimetroMaximo(){
    Nodo* nodo = primero;
    double valorMaximo=nodo->obtener()->perimetro();
    for (unsigned i=1; i<longitud; i++){
        nodo=nodo->obtenerSiguiente();
        if (nodo->obtener()->perimetro() > valorMaximo)
            valorMaximo = nodo->obtener()->perimetro();
        }
    texto(10,10, "El perimetro maximo es de: " + to_string(valorMaximo));
}

void Lista::consultarPerimetroMinimo(){
    Nodo* nodo = primero;
    double valorMinimo=nodo->obtener()->perimetro();
    for (unsigned i=1; i<longitud; i++){
        nodo=nodo->obtenerSiguiente();
        if (nodo->obtener()->perimetro() < valorMinimo)
            valorMinimo = nodo->obtener()->perimetro();
        }
    texto(10,10, "El perimetro minimo es de: " + to_string(valorMinimo));
}

void Lista::mostrarListadoFiguras(){
	for (unsigned pos = 1; pos <= longitud; pos++){
        cout << pos << ") ";
		consultar(pos)->mostrar();
		}
}

void Lista::agregarFigura(){
    borra();
    texto(5,10,"Ingrese 1 si quiere agregar un cuadrado.");
    texto(5,25,"Ingrese 2 si quiere agregar un rectangulo.");
    texto(5,40,"Ingrese 3 si quiere agregar un circulo.");
    unsigned i = leerNumero();
    cout << i;
    double dato, dato2;
    Figura* figura;
    borra();
    switch (i){
        case 1:
            texto(5,10,"Ingrese la longitud del lado: ");
            refresca();
            dato = leerNumero();
            figura = new Cuadrado(dato);
            break;
        case 2:
            texto(5,10,"Ingrese la longitud del primer lado: ");
            dato = leerNumero();
            refresca();
            texto(5,25,"Ingrese la longitud del segundo lado: ");
            refresca();
            dato2 = leerNumero();
            figura = new Rectangulo(dato,dato2);
            break;
        case 3:
            texto(5,10,"Ingrese la longitud del radio: ");
            refresca();
            dato = leerNumero();
            figura = new Circulo(dato);
            break;
        default:
            texto(5,10,"Dato ingresado no valido");
            refresca();
            agregarFigura();
        }
        if (i== 1 || i==2 || i==3){
            borra();
            insertar(figura, longitud+1);
            texto(5,10,"Se ha agregado el objeto correctamente");
            refresca();
            }
}



