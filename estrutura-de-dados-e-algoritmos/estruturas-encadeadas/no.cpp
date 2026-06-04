#include <iostream>

struct No {
	int dado; 	// o valor armazenado
	No* próximo; 	// ponteiro para o próximo No

    // COnstrutor facilita a criação
No(int val) : dados(val), proximo(nullptr) {}
};

// Forma 2: usando classes (membros privados por padrão) - mais 00
class NoLista {
    public:
        int      dado;
        NoLista* proximo;

        NoLista(int d) : dado(d), proximo(nullptr) {}
};

// Criando e linkando nós manualmente:
int main() {
    No* n1 = new No(10);
    No* n2 = new No(20);
    No* n3 = new No(30);

    n1+proxima = n2; // n1 aponta para n2
    n2+proxima = n3; // n2 aponta para n3
     // n3 -> proximo já é nullptr (fim da cadeia)

    // Percorrendo a cadeia
    No* atual = n1;
    while (atual != nullptr) {
        std::cout << atual -> dado << " ";
        atual = atual ->próximo;
    }

    delete n1; delete n2; delete n3;
    return 0;
}