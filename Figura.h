#ifndef FIGURA_H
#define FIGURA_H

class Figura{
	//metodos
    public:
        virtual double superficie() = 0;
        virtual double perimetro() = 0;
        virtual void mostrar() = 0;
};

class Cuadrado : public Figura {
	//atributos
    private:
        double lado;

    //metodos
    public:
        //constructor
        //pre: recibe el valor del lado, que debe ser positivo
        //post: construye un cuadrado
        Cuadrado(double lado);

        //pre: -
        //post: calcula la superficie del cuadrado
        double superficie();

        //pre: -
        //post: calcula el perimetro del cuadrado
        double perimetro();

        //pre: -
        //post: muestra la superficie y el perimetro del cuadrado
        void mostrar();
};

class Circulo : public Figura {
	//atributos
    private:
        double radio;

    public:
        //constructor
        //pre: recibe el valor del radio, que debe ser positivo
        //post: construye un circulo
        Circulo(double radio);

        //pre: -
        //post: calcula la superficie del circulo
        double superficie();

        //pre: -
		//post: calcula el perimetro del circulo
        double perimetro();

        //pre: -
        //post: muestra la superficie y el perimetro del circulo
        void mostrar();

};

class Rectangulo : public Figura {
	//atributos
    private:
        double lado1;
        double lado2;

    public:
        //constructor
        //pre: recibe los valores de los lados, que deben ser positivos
        //post: construye un circulo
        Rectangulo(double lado1, double lado2);

        //pre: -
		//post: calcula la superficie del rectangulo
        double superficie();

        //pre: -
		//post: calcula el perimetro del rectangulo
        double perimetro();

        //pre: -
		//post: muestra la superficie y el perimetro del rectangulo
        void mostrar();

};
#endif // FIGURA_H
