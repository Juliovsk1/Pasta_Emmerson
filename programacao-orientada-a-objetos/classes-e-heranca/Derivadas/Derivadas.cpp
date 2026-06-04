#include "Derivadas.h"

// Circulo
Circulo::Circulo(double r, const std::string& c) : Forma(c), raio(r) {}
double Circulo::area() const { return M_PI * raio * raio; }
double Circulo::perimetro() const { return 2 * M_PI * raio; }
std::string Circulo::tipo() const { return "Circulo"; }

// Retangulo
Retangulo::Retangulo(double w, double h, const std::string& c) : Forma(c), larg(w), alt(h) {}
double Retangulo::area() const { return larg * alt; }
double Retangulo::perimetro() const { return 2 * (larg + alt); }
std::string Retangulo::tipo() const { return "Retangulo"; }

// Triangulo
Triangulo::Triangulo(double a, double b, double c, const std::string& cor)
: Forma(cor), a(a), b(b), c(c) {}
double Triangulo::perimetro() const { return a + b + c; }
std::string Triangulo::tipo() const { return "Triangulo"; }
double Triangulo::area() const {
double s = perimetro() / 2;
return std::sqrt(s * (s - a) * (s - b) * (s - c));
}