#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Fila {
private:
    struct No
    {
        T dado;
        No* prox;
        No(const T& d) : dado(d), prox(nullptr) {}
    };
    No* frente; // dequeue acontece aqui
    No* tras;   // enqueue acontece aqui
    int tamanho;

public: 
    Fila() : frente(nullptr), tras(nullptr), tamanho(0) {}

    // enqueue: adiciona no FINAL - 0(1)
    void enqueue(const T& val) {
        No* novo = new No(val);
        if (!tras) {        // fila vzaia
            frente = tras = novo;
        } else {
            tras->prox = novo;
            tras = novo;
        };
        tamanho++;
    };

    // dequeue: remove do INICIO '0(1)
    T dequeue() {
        if (empty()) throw std::underflow_error("Fila vazia");
        No* temp = frente;
        T   val  = frente-> dado;
        frente = frente->prox;
        if (!frente) tras = nullptr; // fila ficou vazia
        delete temp;
        tamanho --;
        return val;
    }

    T& front() {
        if (empty()) throw std::underflow_error("Fila vazia!");
        return frente->dado;
    }

    bool empty()    const { return frente == nullptr; }
    int size()      const {return tamanho; }

    ~Fila() { while (!empty()) dequeue(); }
};

// Uso: simulação de impressora
int main() {
    Fila<std::string> impressora;
    impressora.enqueue("relatorio.pdf");
    impressora.enqueue("notas.doc");
    impressora.enqueue("curriculo.pdf");

    while (!impressora.empty()) {
        cout << "Imprimindo: " << impressora.dequeue() << "\n";
    }
}
