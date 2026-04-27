#include <iostream>

using namespace std;

int main() {
    int x[] = {0, 6, 12, 18, 24};
    int jumlah = 5;
    int dataDicari;

    cout << "Masukan data yang dicari: ";
    cin >> dataDicari;

    int L = 0;
    int R = jumlah - 1;
    int mid;
    bool ditemukan = false;

    while (L <= R) {
        mid = (L + R) / 2;

        if (x[mid] == dataDicari) {
            ditemukan = true;
            break;
        } else if (x[mid] < dataDicari) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    if (ditemukan) {
        cout << "Bilangan ditemukan" << endl;
    } else {
        cout << "Bilangan tidak ditemukan." << endl;
    }

    return 0;
}
