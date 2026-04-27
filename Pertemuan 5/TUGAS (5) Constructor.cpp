#include <iostream>
using namespace std;

// Mendefinisikan class bernama 'contoh'
class contoh {
    private:
        int nilai; // Variabel private yang hanya bisa diakses di dalam class

    public:
        // Ini adalah CONSTRUCTOR
        // Memiliki nama yang sama dengan class dan tidak memiliki return type
        // Berfungsi untuk menginisialisasi objek saat pertama kali dibuat
        contoh (int n) {
            nilai = n; // Memberi nilai pada variabel 'nilai' berdasarkan input 'n'
        }

        // Method untuk mengambil/mengembalikan nilai yang tersimpan
        int getNum() {
            return nilai;
        }
};

int main() {
    // Membuat objek 'obj' dari class 'contoh' sekaligus memberikan argumen 10
    // Argumen 10 ini akan diterima oleh constructor di atas
    contoh obj(10);

    // Menampilkan nilai yang telah diinput ke layar
    cout << "nilai yang diinput: " << obj.getNum() << endl;

    return 0;
}
