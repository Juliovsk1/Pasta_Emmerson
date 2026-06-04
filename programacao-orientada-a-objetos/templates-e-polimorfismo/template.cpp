#include <iostream>

using namespace std;


//Sem template: Frágil, trabalhoso
int somaInt (int a,int b) { return a + b; }
double somaInt (double a,double b) { return a + b; }
float somaInt (float a,float b) { return a + b; }

//Com template: rápido e fácil, robusto
template<typename T>
T soma (T a, T b) {
    return a +b;
}

template<typename T>
T meuMax(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T, typename U>
void imprimePar(T a, T b) {
    cout << "(" << a << ", " << b << ")";
}

// N é um valor inteiro, não UM TIPO - definido em tempo de compilação
template<typename T, int N>
void imprimeN(T val) {
    for(int i = 0; i < N; ++i){
        cout << val << " ";
    }
    cout << "";
}

// Exemplo completo: Pilha genérica
template<typename T>
class Pilha {
private:
    std::vector<T> dados;

public:
    void   push(const T& val) { dados.push_back(val); }
    void   pop()              { dados.pop_back(); }
    T      topo()  const      { return dados.back(); }
    bool   vazio() const      { return dados.empty(); }
    size_t size()  const      { return dados.size(); }
};

template<typename Chave, typename Valor, int Cap = 100>
class MapaSimples {
    array<pair< Chave, Valor>, Cap> dados;
    int n = 0;
public:
    void inserir(Chave k, Valor v) { dados[n++] = {k, v}; }
};

MapaSimples<string, int> notas; // Cap = 100 (padrão)
MapaSimples<string, int, 10> pequeno; // Cap = 10


// template genérico
template<typename T>
class Impressor {
public:
    void imprimir(T val) {
        cout << "Valor: " << val << "";
    }
};

// Especialização total para bool - sintaxe: template<>
template<>

class Impressor<bool> {
public:
    void imprimir(bool val) {
        cout << (val ? "verdadeira" : "falso") << "";
    }
};

// Parcial: quando T == U
template<typename T>
struct imprimePar<T, T> {
    void info() {cout << "Par de tipos iguais"; }
};

//Parcial: segundo tipo é ponteiro
template<typename T, typename U>
struct imprimePar<T, U*> {
    void info() { cout << "Par com ponteiro"; }
};

template<typename T>
T somaTotal(T val) {return val; }

// Caso recursivo: desembrulha o primeiro, processa o restante
template<typename T, typename ... Args>
T somaTotal(T primeiro, Args ... resto) {
    return primeiro + somaTotal(resto ... );
}

template<typename... Args>
auto somaFold(Args ... args) {
    return (... + args); //fold unário a esquerda
}

template<typename... Args>
void printTodos(Args ... args) {
    ((cout << args << " "), ...); // fold com vírgula
    cout << endl;
}

int main(){

int r1 = soma(3, 4);  // T = int
double r2 = soma(1.5, 2.3); // T = double
float r3 = soma(1.0f, 2.0f); // T = float


auto n1 = meuMax(10, 20);
auto n2 = meuMax(2.14, 2.71);
auto n3 = meuMax<float>(1.0f, 5.0f);

Pilha<int>   pi; // Pilhas inteiros
Pilha<std::string> ps; //Pilhas strings

pi.push(10); pi.push(20); pi.push(30);
cout << pi.topo() << ""; // 30
pi.pop();
cout << pi.topo() << ""; // 20


ps.push("ola"); ps.push("mundo");
cout << ps.topo() << ""; // mundo
};