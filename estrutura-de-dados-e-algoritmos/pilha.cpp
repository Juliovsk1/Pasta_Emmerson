// sistema clássico Lifo - Last In First Out

// Push(empurra), Pop(tira)
// Peek()/top() - Lê o topo sem remover

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Pilha {
private:
    struct No {
        T dado;
        No* prox;
        No(const T& d) : dado(d),prox(nullptr) {}
    };
    No* topo;
    int tamanho;

public:
    Pilha() : topo(nullptr), tamanho(0) {}

    void push(const T& val) {   // empilha O(1)
        No* novo = new No(val);
        novo->prox = topo;
        topo = novo;
        tamanho++;
    }

    T pop() {               // desempilha - O(1)
        if (empty())
            throw std::underflow_error("Pilha vazia!");
        No* temp = topo;
        T   val = topo->dado;
        topo = topo->prox;
        delete temp;
        tamanho--;
        return val;
    }

    T& peek() {     // consulta topp - O(1)
        if (empty()) throw std::underflow_error("Pilha vazia!");
        return topo->dado;
    }

    bool empty()    const {return topo == nullptr; }
    int size()      const {return tamanho; }
};

// Aplicação clássica: verificador de parênteses balanceados
bool balanceado(const std::string& expr) {
    Pilha<char> p;
    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') p.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (p.empty()) return false;
            char t = p.pop();
            if ((c == ')' && t != '(') || (c==']' && t!='[') ||
        (c=='}' && t!='{')) return false;
        }
    }
    return p.empty();
}

int main() {
    cout << balanceado("{[()]}") << "\n";
    cout << balanceado("{[(]}") << "\n";
}
