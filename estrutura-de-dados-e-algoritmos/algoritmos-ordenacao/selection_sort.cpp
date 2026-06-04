#include <iostream>
#include <vector>
#include <algorithm> //std::swap

void selectionSort(std::vector<int>& v) {
    int n = v.size();

    for(int i = 0; i < n - 1; i++) {
        // Encontra o índice do menor elemento em v[i..., n]
        int idxMin = i;
        for(int j = i + 1; j < n; ++j) {
            if (v[j] < v[idxMin])
            idxMin = j;
        }

        // Coloca o menor na posição correta
        if (idxMin != i)
            std::swap(v[i], v[idxMin]);
    }
}

int main(){
    std::vector<int> v = {64,25,12,2,11};

    std::cout << "Antes: ";
    for (int x : v) std::cout << x << " ";

    selectionSort(v);

    std::cout << "\nDepois: ";
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
}