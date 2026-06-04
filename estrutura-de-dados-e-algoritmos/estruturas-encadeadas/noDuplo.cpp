#include <iostream>

struct NoDuplo {
	int dado; 	// o valor armazenado
	NoDuplo* próximo; 	// ponteiro para o próximo No
    NoDuplo* anterior; 	// ponteiro para o No anterior

    // COnstrutor facilita a criação
NoDuplo(int d) : dados(d), proximo(nullptr), anterior(nullptr) {}
};

// Para árvores binárias (ED2), a estrutura expande para:
struct NoArvore {
    public:
        int      chave;
        NoArvore* esquerdo; // subárvore esquerdo
        NoArvore* direito; // subárvore esquerdo
        // Opcional (ED2): NoArvore* pai;

        NoLista(int k) : chave(k), esquerdo(nullptr), direito(nullptr) {}
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