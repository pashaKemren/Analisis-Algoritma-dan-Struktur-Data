#include <iostream>
#include <string>

using namespace std;

int main() {
    string judul[] = {"Algoritma", "Basis Data", "C++ Dasar", "Jaringan", "Sistem Operasi"};
    string rak[] = {"Rak A1", "Rak A2", "Rak B1", "Rak B2", "Rak C1"};
    int jumlah = 5;
    
    string cari;
    cout << "Masukkan Judul Buku: ";
    getline(cin, cari);

    int L = 0;
    int R = jumlah - 1;
    int mid;
    int posisi = -1;

    while (L <= R) {
        mid = (L + R) / 2;

        if (judul[mid] == cari) {
            posisi = mid;
            break;
        } else if (judul[mid] < cari) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    if (posisi != -1) {
        cout << "Buku ditemukan! Letak: " << rak[posisi] << endl;
    } else {
        cout << "Maaf, buku tidak ditemukan." << endl;
    }

    return 0;
}
