#ifndef FIGURA_H
#define FIGURA_H

class Figura{

    public:
        virtual double superficie() = 0;
        virtual double perimetro() = 0;
        virtual void mostrar() = 0;
};

class Cuadrado : public Figura {

    private:
        double lado;

    public:
        Cuadrado(double lado);
        double superficie();
        double perimetro();
        void mostrar();
};

class Circulo : public Figura {

    private:
        double radio;

    public:
        Circulo(double radio);
        double superficie();
        double perimetro();
        void mostrar();

};

class Rectangulo : public Figura {

    private:
        double lado1;
        double lado2;

    public:
        Rectangulo(double lado1, double lado2);
        double superficie();
        double perimetro();
        void mostrar();

};
#endif // FIGURA_H
