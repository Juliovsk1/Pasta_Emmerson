#include <iostream>


void camadaInterna() {
    throw std::runtime_error("Falha na camda interna");
}

void camadaMedia(){
    try {
        camadaInterna();
    }
    catch (const std::exception& e){
        std::cerr << "[media] Logando erro: " << e.what() << "\n";
        throw; // re-lança a MESMA exceção original
    }
}


int main() {
    try { camadaMedia();}

    catch (const std::exception& e) {
        std::cerr << "[Main] Tratando: " << e.what() << "\n";
    }
}