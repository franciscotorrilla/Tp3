#include <iostream>
#include <fstream>
#include "Figura.h"
#include "Lista.h"
using namespace std;

int main(){
    ifstream archivo;
    archivo.open("figuras.txt");
    char character;
    double dato, dato2;
    unsigned contador=1;
    Lista lista;
    Figura* figura;
    while (archivo>>character){
        archivo >> dato;
        if (character=='A'){
            figura = new Cuadrado(dato);
        }
        else if(character=='B'){
            archivo>>dato2;
            figura = new Rectangulo(dato,dato2);
        }
        else{
            figura = new Circulo(dato);
        }
        lista.insertar(figura, contador);
        contador ++;
    }
    lista.menu();

    archivo.close();
}





