#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

class Lista {
	//atributos
    private:
        Nodo* primero;
        unsigned int longitud;

	//metodos
    public:
        //constructor
        //pre: -
        //pos: crea una lista vacia, primero = 0 y longitud = 0
        Lista();

        //destructor
        virtual ~Lista();

        unsigned obtenerLongitud();

        //pre 0 < pos <= obtenerLongitud() +1
        // pos agrega el dato en la pos
        void insertar ( Tipo* e, unsigned pos);

        //pre 0 < pos <= obtenerLongitud()i='1'
        // pos quita el dato de la lista y libera la memoria
        void borrar( unsigned pos);

        // pre  0 < pos <= obtenerLongitud()
        // pos devuelve el dato de la lista en pos
        Tipo* consultar(unsigned pos);

        //pre: -
        //pos: devuelve true si la lista esta vacia y false en caso contrario
        bool listaVacia();

        //pre: -
        //pos: le muestra al usuario un menu con las distintas acciones que puede elegir
        void menu();

    private:
        //pre: recibe la posicion del nodo que se quiere obtener
        //pos: devuelve el nodo deseado
        Nodo* obtenerNodo(unsigned pos);

        //pre: recibe el numero de la opcion que se desea ejecutar
        //pos: ejecuta la opcion deseada
        void opciones(char i);

        //pre: -
        //pos: agrega una figura en la posicion deseada de la lista
        void agregarFigura();

        //pre: -
        //pos: muestra la superficie y el perimetro de todas las figuras de la lista
        void mostrarListadoFiguras();

        //pre: -
        //pos: imprime la superficie maxima
        void consultarSuperficieMaxima();

        //pre: -
		//pos: imprime la superficie minima
        void consultarSuperficieMinima();

        //pre: -
		//pos: imprime el perimetro maximo
        void consultarPerimetroMaximo();

        //pre: -
		//pos: imprime el perimetro minimo
        void consultarPerimetroMinimo();
};

#endif // LISTA_H
