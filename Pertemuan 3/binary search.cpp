#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[20], n, x;

    cout << "Masukkan jumlah Bilangan: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i << " = ";
        cin >> arr[i];
    }

    sort(arr, arr + n);

    cout << "\nData setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nMasukkan angka yang dicari: ";
    cin >> x;

    int hasil = binarySearch(arr, n, x);

    if (hasil != -1) {
        cout << "Angka ditemukan pada index ke-" << hasil;
    } else {
        cout << "Angka tidak ditemukan";
    }

    return 0;
}
