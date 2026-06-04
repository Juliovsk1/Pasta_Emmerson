#ifndef FORMA_H
#define FORMA_H

#include <iostream>
#include <string>

class Forma {
protected:
std::string cor;

public:
Forma(const std::string& c) : cor(c) {}
virtual double area() const = 0;
virtual double perimetro() const = 0;
virtual std::string tipo() const = 0;
virtual void descrever() const;
virtual ~Forma() = default;
};

#endif