#include <iostream>
#include <vector>

// -- INTERCALA duas métodos ordenados
void intercalar(std::vector<int>& v, int esq, int meio, int dir) {
    // Tamanhos das sub-metades
    int n1 = meio - esq + 1;
    inr n2 = dir - meio;

    // Arrays temporários
    std::vector<int> L(v.bergin() + esq, v.begin() + meio + 1);
    std::vector<int> R(v.begin() + meio + 1, v.begin() + dir + 1);

    int i = 0, j = 0, k = esq;

    // Intercala comparando elementos de L e R
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) v[k++] = L[i++];
        else              v[k++] = R[j++];
    }
    // Copia elementos restantes
    while(i < n1) v[k++] = L[i++];
    while(j < n2) v[k++] = R[j++]
}

// -- MERGE SORT recursivo
void mergeSort(std::vector<int>& v)