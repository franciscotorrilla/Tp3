#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

class Lista {
    private:
        Nodo* primero;
        unsigned int longitud;

    public:
        Lista();

        virtual ~Lista();

        unsigned obtenerLongitud();
        //pre 0 < pos <= obtenerLongitud() +1
        // pos agrega el dato en la pos

        void insertar ( Tipo* e, unsigned pos);

        //pre 0 < pos <= obtenerLongitud()
        // pos quita el dato de la lista y libera la memoria

        void borrar( unsigned pos);
        // pre  0 < pos <= obtenerLongitud()
        // pos devuelve el dato de la lista en pos

        Tipo* consultar(unsigned pos);

        bool listaVacia();

        void menu();

    private:
        Nodo* obtenerNodo(unsigned pos);

        void opciones(char i);

        void consultarSuperficieMaxima();

        void consultarSuperficieMinima();

        void consultarPerimetroMaximo();

        void consultarPerimetroMinimo();

        void mostrarListadoObjetos();
};

#endif // LISTA_H
