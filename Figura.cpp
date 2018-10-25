#include "Figura.h"
#include <iostream>
using namespace std;

Cuadrado::Cuadrado(double lado){
this->lado = lado;
}

double Cuadrado::superficie() {
return lado * lado;
}

double Cuadrado::perimetro(){
return lado * 4;
}

void Cuadrado ::mostrar() {
cout << "Cuadrado de superficie " << superficie() << " y perimetro " << perimetro() << endl;
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
}

