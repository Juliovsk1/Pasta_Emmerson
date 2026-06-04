#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& v) {
    int n = v.size();

    for (int i = 1; i < n; i++) {
        int chave = v[i]; // elemento a ser inserido
        int j     = i - 1;

        // Desloca elementos maiores que a chave para a 
        while (i >= 0 && v[j] > chave) {
            v[j + 1] = v[j]; // abre espaço
            --j;
        }
        v[j + 1] = chave; // insere na posição correta
    }
}

int main() {
    std::vector<int> v = {5, 2, 4, 6, 1, 3};

    std::cout << "Antes: ";
    for (int x : v) std::cout << x << " ";

    insertionSort(v);

    std::cout << "\nDepois: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}