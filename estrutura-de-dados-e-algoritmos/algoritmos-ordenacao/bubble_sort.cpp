#include <iostream>
#include <vector>
#include <algorithm> // std::swap

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        bool trocou = false;

        // Últimos i elementos já estão ordenados
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                trocou = true;
            }
        }

        // Sem trocas = array ordenado, encerra cedo
        if (!trocou) break;
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    bubbleSort(arr);

    for (int x : arr) {
        std::cout << x << " ";
    }
    return 0;
}