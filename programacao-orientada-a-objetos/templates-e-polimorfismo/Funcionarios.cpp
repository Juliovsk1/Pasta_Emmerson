#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

// -- CLASSE ABSTRATA BASE -----------------------------
class Funcionario {
protected:
    std::string nome;
    std::string cargo;

public:
    Funcionario(const std::string& n, const std::string& c)
        : nome(n), cargo(c) {}

    // Contrato: toda derivada calcula seu próprio salário
    virtual double calcularSalario() const = 0;
    virtual std::string tipoPagamento() const = 0;

    virtual void exibirResumo() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "["  << tipoPagamento() << "] "
                  << nome << " (" << cargo << ")"
                  << " ? R$ " << calcularSalario() << "\n";
    }

    virtual ~Funcionario() = default;
};

// -- HORISTA -------------------------------------------
class Horista : public Funcionario {
    double valorHora;
    int    horasTrabalhadas;
public:
    Horista(const std::string& n, double vh, int ht)
        : Funcionario(n, "Horista"), valorHora(vh), horasTrabalhadas(ht) {}

    double calcularSalario() const override {
        return valorHora * horasTrabalhadas;
    }
    std::string tipoPagamento() const override { return "POR HORA"; }
};

// -- ASSALARIADO ---------------------------------------
class Assalariado : public Funcionario {
    double salarioBase;
public:
    Assalariado(const std::string& n, double sb)
        : Funcionario(n, "Assalariado"), salarioBase(sb) {}

    double calcularSalario() const override { return salarioBase; }
    std::string tipoPagamento() const override { return "FIXO"; }
};

// -- COMISSIONADO --------------------------------------
class Comissionado : public Funcionario {
    double salarioBase;
    double comissaoPct;   // ex: 0.08 = 8%
    double totalVendas;
public:
    Comissionado(const std::string& n, double sb, double pct, double tv)
        : Funcionario(n, "Vendedor"), salarioBase(sb),
          comissaoPct(pct), totalVendas(tv) {}

    double calcularSalario() const override {
        return salarioBase + (comissaoPct * totalVendas);
    }
    std::string tipoPagamento() const override { return "COMISSÃO"; }
};

// -- FOLHA DE PAGAMENTO --------------------------------
void processarFolha(
    const std::vector<std::unique_ptr<Funcionario>>& equipe)
{
    double totalFolha = 0;
    std::cout << "------- FOLHA DE PAGAMENTO -------\n";
    for (const auto& f : equipe) {
        f->exibirResumo();         // polimorfismo!
        totalFolha += f->calcularSalario();
    }
    std::cout << "---------------------------------\n";
    std::cout << "Total: R$ " << totalFolha << "\n";
}

int main() {
    std::vector<std::unique_ptr<Funcionario>> equipe;

    equipe.push_back(std::make_unique<Assalariado>("Ana",    8500.00));
    equipe.push_back(std::make_unique<Horista>("Bruno",  45.00, 160));
    equipe.push_back(std::make_unique<Comissionado>("Carla", 2000, 0.08, 30000));

    processarFolha(equipe);
    // [FIXO]    Ana   (Assalariado) ? R$ 8500.00
    // [POR HORA] Bruno (Horista)    ? R$ 7200.00
    // [COMISSÃO] Carla (Vendedor)   ? R$ 4400.00
    // Total: R$ 20100.00
