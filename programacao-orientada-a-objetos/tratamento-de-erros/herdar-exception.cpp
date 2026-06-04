#include <iostream>

// Boa prática herdar de std::exception ou de um de seus filhos
class SaldoInsuificenteException : public std::runtime_error{
    private:
        double saldo_disponivel;
        double valor_solicitado;
    public:
        SaldoInsuificenteException(double disp, double sol) : std::runtime_error("Saldo insuficiente"), saldo_disponivel(disp), valor_solicitado(sol){}

    
    double getSaldo() const {return saldo_disponivel; }
    double getSolicitando() const {return valor_solicitado; }

    // Mensagem detalhada (override de what())
    const char* what() const noexcept override {
        return "Operação negada: saldo insuficiente para a transação";
    }
};