#include <iostream>
using namespace std;

// Fungsi swap
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot terakhir
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi tampil
void tampil(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {105, 102, 108, 101, 109, 104, 107};
    int n = 7;

    cout << "Sebelum sorting: ";
    tampil(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Setelah sorting: ";
    tampil(arr, n);
}
