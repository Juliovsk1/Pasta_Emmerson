#include <vector>

#include <memory> // unique_ptr

int main(){
    // vetor de ponteiros BASE - pode guardar qualquer Forma!

    std::vector<std::unique_ptr<Forma>> formas:


    formas.push_back(std::make_unique<Circulo>(5.0, "vermelho"));
    formas.push_back(std::make_unique<Retangulo>(4.0, 6.0, "azul"));
    formas.push_back(std::make_unique<Triangulo>(3.0, 4.0, 5.0, "verde"));

    // Percorre via ponteiro base - polimorfismo em ação!

    for (const auto& f : formas) {
        f->descrever();     // chama o método correto de cada derivada
    }
}