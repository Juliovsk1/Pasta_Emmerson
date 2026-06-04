#include <iostream>
#include <algorithm> // std::swap
#include <vector>

// Retorna o índice de pivô após o particionamento
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // pivô = Último elemento
    int i = low - 1;      // índice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i+1], arr[high]); // coloca o pivô na posição correta
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1); // esquerda
        quickSort(arr, pivotIndex + 1, high); // direita
    }
}
int main() {
    std::vector<int> arr = {10, 7, 8, 9, 5, 1};
    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        std::cout << x << " ";
    }

    return 0;
}