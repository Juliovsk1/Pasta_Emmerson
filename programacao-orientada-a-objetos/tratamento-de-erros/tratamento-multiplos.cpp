#include <iostream>
#include <string> 

void processarIdade(int idade) {
    if (idade < 0)
        throw std::invalid_argument("Idade negativa!");
    if(idade > 150)
        throw std::out_of_range("Idade improvável");
    std::cout << "Idade válida: " << idade << "";
}


int main(){
    try{
        processarIdade(-5);
    }
    catch(const std::exception& e){
        std::cerr<< "[Argumento inválido]" << e.what() << '\n';
    }
    catch(const std::out_of_range& e) {
        std::cerr << "[Fora do intervalo]" << e.what() << "\n";
    }
    catch (...){    //captura QUALQUER exceção
        std::cerr << "[Erro desconhecido]";
    }
}