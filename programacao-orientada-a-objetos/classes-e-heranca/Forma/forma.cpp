#include <vector>
#include <memory>
#include <iostream>
#include "forma.h"
#include "Derivadas.h"

int main() {
std::vector<std::unique_ptr<Forma>> formas;

formas.push_back(std::make_unique<Circulo>(5.0, "vermelho"));
formas.push_back(std::make_unique<Retangulo>(4.0, 6.0, "azul"));
formas.push_back(std::make_unique<Triangulo>(3.0, 4.0, 5.0, "verde"));

for (const auto& f : formas) {
f->descrever();
}

return 0;
}