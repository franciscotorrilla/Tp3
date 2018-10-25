#include "Lista.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

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

        cout << "Ingrese 0 para cerrar el menu." <<endl;
		cout << "Ingrese 1 para consultar que objeto hay en determinada posicion." <<endl;
		cout << "Ingrese 2 para dar de baja un objeto en determinada posicion." <<endl;
		cout << "Ingrese 3 para agregar un nuevo objeto de manera manual." <<endl;
		cout << "Ingrese 4 para listar todos los objetos." << endl;
		cout << "Ingrese 5 para consultar la superficie maxima." <<endl;
		cout << "Ingrese 6 para consultar la superficie minima." <<endl;
		cout << "Ingrese 7 para consultar el perimetro maximo." <<endl;
		cout << "Ingrese 8 para consultar el perimetro minimo."<<endl;
		cin >> i;
		system("CLS");
		opciones(i);
		sleep(2);
    	}
    }


void Lista::opciones(char i){
    unsigned pos;
    switch (i){
		case '0':
			break;
        case '1':
            cout << "Ingrese la posicion: ";
            cin >> pos;
            if (pos<=longitud)
                consultar(pos)->mostrar();
            else
                cout << "No hay elemento en dicha posicion." <<endl;
            break;
        case '2':
            cout << "Ingrese la posicion: ";
            cin >> pos;
            if (pos<=longitud){
                cout << "Se ha dado de baja al ";
                consultar(pos)->mostrar();
                borrar(pos);
                }
            else
                cout << "No hay elemento en dicha posicion." <<endl;
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
        default: cout << "Dato ingresado invalido" << endl;
            }
        cout<< endl;
       }

void Lista::consultarSuperficieMaxima(){
    Nodo* nodo = primero;
    int valorMaximo=nodo->obtener()->superficie();
    for (unsigned i=1; i<longitud; i++){
        nodo=nodo->obtenerSiguiente();
        if (nodo->obtener()->superficie()>valorMaximo)
            valorMaximo = nodo->obtener()->superficie();
        }
    cout << "La superficie maxima es de: " << valorMaximo <<endl;
}

void Lista::consultarSuperficieMinima(){
    Nodo* nodo = primero;
    int valorMinimo=nodo->obtener()->superficie();
    for (unsigned i=1; i<longitud; i++){
        nodo=nodo->obtenerSiguiente();
        if (nodo->obtener()->superficie() < valorMinimo)
            valorMinimo = nodo->obtener()->superficie();
        }
    cout << "La superficie minima es de: " << valorMinimo <<endl;
}

void Lista::consultarPerimetroMaximo(){
    Nodo* nodo = primero;
    int valorMaximo=nodo->obtener()->perimetro();
    for (unsigned i=1; i<longitud; i++){
        nodo=nodo->obtenerSiguiente();
        if (nodo->obtener()->perimetro() > valorMaximo)
            valorMaximo = nodo->obtener()->perimetro();
        }
    cout << "El perimetro maximo es de: " << valorMaximo <<endl;
}

void Lista::consultarPerimetroMinimo(){
    Nodo* nodo = primero;
    int valorMinimo=nodo->obtener()->perimetro();
    for (unsigned i=1; i<longitud; i++){
        nodo=nodo->obtenerSiguiente();
        if (nodo->obtener()->perimetro() < valorMinimo)
            valorMinimo = nodo->obtener()->perimetro();
        }
    cout << "El perimetro minimo es de: " << valorMinimo <<endl;
}

void Lista::mostrarListadoFiguras(){
	for (unsigned pos = 1; pos <= longitud; pos++){
        cout << pos << ") ";
		consultar(pos)->mostrar();
		}
}

void Lista::agregarFigura(){
    char i;
    cout << "Ingrese 1 si quiere agregar un cuadrado." <<endl;
    cout << "Ingrese 2 si quiere agregar un rectangulo." <<endl;
    cout << "Ingrese 3 si quiere agregar un circulo."<< endl;
    cin >> i;
    double dato, dato2;
    Figura* figura;
    switch (i){
        case '1':
            cout << "Ingrese la longitud del lado: ";
            cin >> dato;
            figura = new Cuadrado(dato);
            break;
        case '2':
            cout << "Ingrese la longitud del primer lado: ";
            cin >> dato;
            cout << "Ingrese la longitud del segundo lado: ";
            cin >> dato2;
            figura = new Rectangulo(dato,dato2);
            break;
        case '3':
            cout << "Ingrese la longitud del radio: ";
            cin >> dato;
            figura = new Circulo(dato);
            break;
        default:
            cout << "Dato ingresado invalido" << endl;
            agregarFigura();
        }
        if (i=='1' || i=='2' || i=='3'){
            unsigned pos;
            cout << "Ingrese en que posicion se quiere agregar:";
            cin >> pos;
            while (pos<1 || pos>longitud+1){
                cout << "Ingrese una posicion valida:";
                cin >> pos;
                }
            insertar(figura, pos);
            cout << "Se ha agregado el objeto correctamente" <<endl;
            }
    }






