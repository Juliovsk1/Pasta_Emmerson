#include <iostream>

// Problema: o chamador pode simplesmente ignorar o erro
int dividir(int a, int b, int& resultado) {
	if(b == 0) return -1; // código de erro
	resultado = a / b;
	return 0; // sucesso
}

//Abordagem moderna – Exceções:
double dividir(double a, double b) {
	if (b == 0.0)
        throw std::invalid_argument("Divisor não pode ser zero!");
    return a / b;
}

int main() {
    try {
        double r = dividir(10.0, 2.0); // lança a exceção
        std::cout << "Resultado: " << r << ""; 
    }

    catch(const std::invalid_argument& e){
        std::cerr << "Erro: " << e.what() << "";
    }
    return 0;
}