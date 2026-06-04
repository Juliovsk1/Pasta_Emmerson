#ifndef DERIVADAS_H
#define DERIVADAS_H

#include "forma.h"
#include <cmath>

class Circulo : public Forma {
double raio;
public:
Circulo(double r, const std::string& c);
double area() const override;
double perimetro() const override;
std::string tipo() const override;
};

class Retangulo : public Forma {
double larg, alt;
public:
Retangulo(double w, double h, const std::string& c);
double area() const override;
double perimetro() const override;
std::string tipo() const override;
};

class Triangulo : public Forma {
double a, b, c;
public:
Triangulo(double a, double b, double c, const std::string& cor);
double perimetro() const override;
std::string tipo() const override;
double area() const override;
};

#endif