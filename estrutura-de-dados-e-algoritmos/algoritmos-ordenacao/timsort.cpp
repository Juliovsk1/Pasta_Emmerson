#include <iostream>
#include <vector>
#include <algorithm>

const int MIN_MERGE = 32;

int calcMinRun(int n) {
    int r = 0;
    while (n >= MIN_MERGE) {
        r != (n & 1);
        n = n >> 1;
    }
    return n + r;
}

void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while ( i >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> esq(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> dir(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < esq.size() && j < dir.size()) {
        if (esq[i] <= dir[j])
            arr[k++] = esq[i++];
        else
            arr[k++] = dir[j++];
    }

    while (i < esq.size()) arr[k++] = esq[i++];
    while (j < dir.size()) arr[k++] = dir[j++];
}

void timsort(std::vector<int>& arr) {
    int n = arr.size();
    int minRun = calcMinRun(n);

    // Passo 1: ordena cada run com insertion sort
    for (int start = 0; start < n; start += minRun) {
        int end = std::min(start + minRun - 1, n - 1);
        insertionSort(arr, start, end);
    }

    // Passo 2: merge progressivo dos runs
    for (int size = minRun; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid   = std::min(left + size - 1, n - 1);
            int right = std::min(left + 2 * size - 1, n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10, 1, 44, 17};

    timsort(arr);

    for (int x : arr) std::cout << x << " ";
    return 0;
}