#include <iostream>
using namespace std;

int main () {
    int nilai[20];
    int posisi[20];
    int n, bil, jmlh = 0;
    bool ketemu = false;

    cout << "Masukan jumlah deret bilangan = ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Nilai bilangan ke-" << i << " = ";
        cin >> nilai[i];
    }

    cout << "\nDeret Bilangan = ";
    for (int i = 0; i < n; i++) {
        cout << nilai[i] << " ";
    }

    cout << "\n\nMasukan bilangan yang dicari = ";
    cin >> bil;

    for (int i = 0; i < n; i++) {
        if (nilai[i] == bil) {
            ketemu = true;
            posisi[jmlh] = i;
            jmlh++;
        }
    }

    if (ketemu) {
        cout << "\nBilangan " << bil << " ditemukan pada posisi: ";
        for (int i = 0; i < jmlh; i++) {
            cout << posisi[i] << " ";
        }
    } else {
        cout << "\nBilangan tidak ditemukan";
    }

    return 0;
}
