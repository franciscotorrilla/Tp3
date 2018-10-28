#include "Figura.h"
#include <iostream>
#include <string>
#include "miniwin.h"
using namespace std;
using namespace miniwin;

Cuadrado::Cuadrado(double lado){
this->lado = lado;
}

double Cuadrado::superficie() {
return lado * lado;
}

double Cuadrado::perimetro(){
return lado * 4;
}

void dibujarRectangulos(double lado1,double lado2,string superficie, string perimetro) {
    string mensaje = "Rectangulo de superficie " + superficie + " y perimetro " + perimetro;
    texto(10,20,mensaje);
    rectangulo(lado1*25+100,lado2*25+100,50,50);
    refresca();
    texto(5,450,"Enter para continuar...");
    refresca();
    while(tecla() != RETURN);
    borra();
}

void Cuadrado ::mostrar() {
    cout << "Cuadrado de superficie " << superficie() << " y perimetro " << perimetro() << endl;
    dibujarRectangulos(lado,lado,to_string(superficie()),to_string(perimetro()));
}

void dibujarCirculo(double radio, string superficie, string perimetro) {
    string mensaje = "Circulo de superficie " + superficie + " y perimetro " + perimetro;
    texto(10,20,mensaje);
    circulo(250,250,radio*15);
    refresca();
    texto(5,450,"Enter para continuar...");
    refresca();
    while(tecla() != RETURN);
    borra();
}

Circulo::Circulo(double radio){
    this ->radio = radio;
}

double Circulo::superficie() {
return radio * radio * 3.1416;
}

double Circulo::perimetro(){
return radio * 2 * 3.1416;
}

void Circulo::mostrar() {
    cout << "Circulo de superficie " << superficie() << " y perimetro " << perimetro() << endl;
    dibujarCirculo(radio,to_string(superficie()),to_string(perimetro()));
}

Rectangulo::Rectangulo(double lado1, double lado2){
this ->lado1 = lado1;
this -> lado2 = lado2;
}

double Rectangulo::superficie() {
return lado1 * lado2;
}

double Rectangulo::perimetro(){
return (2 * lado1) + (2 * lado2);
}

void Rectangulo::mostrar() {
cout << "Rectangulo de superficie " << superficie() << " y perimetro " << perimetro() << endl;
dibujarRectangulos(lado1,lado2,to_string(superficie()),to_string(perimetro()));

}

