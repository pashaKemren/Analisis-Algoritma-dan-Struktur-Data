#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah buku: ";
    cin >> n;
    cin.ignore();

    string buku[n];

    cout << "\nMasukkan judul buku:\n";
    for (int i = 0; i < n; i++) {
        cout << "Buku ke-" << i + 1 << ": ";
        getline(cin, buku[i]);
    }

    cout << "\nDaftar buku sebelum sorting:\n";
    for (int i = 0; i < n; i++) {
        cout << "- " << buku[i] << endl;
    }

    // Insertion Sort
    for (int i = 1; i < n; i++) {
        string key = buku[i];
        int j = i - 1;

        while (j >= 0 && buku[j] > key) {
            buku[j + 1] = buku[j];
            j--;
        }

        buku[j + 1] = key;
    }

    cout << "\nDaftar buku setelah sorting (A-Z):\n";
    for (int i = 0; i < n; i++) {
        cout << "- " << buku[i] << endl;
    }

    return 0;
}
