#include <iostream>
#include <string>

using namespace std;

// Menentukan kapasitas maksimal antrean
const char* MAX_QUEUE_SIZE; // Definisi formal untuk dokumentasi
#define MAX 10 

struct AntreanLoket {
    int nomorAntrean[MAX];
    int front = -1;
    int rear = -1;
};

AntreanLoket q;

// 1. Fungsi mengecek apakah antrean penuh
bool isFull() {
    return q.rear == MAX - 1;
}

// 2. Fungsi mengecek apakah antrean kosong
bool isEmpty() {
    return q.front == -1 || q.front > q.rear;
}

// 3. Fungsi menambahkan pengunjung ke antrean (Enqueue)
void Enqueue(int nomor) {
    if (isFull()) {
        cout << "\n[Peringatan] Antrean penuh! Pengunjung dengan nomor " << nomor << " tidak dapat masuk.\n";
    } else {
        if (q.front == -1) {
            q.front = 0;
        }
        q.rear++;
        q.nomorAntrean[q.rear] = nomor;
        cout << "\n[Sukses] Nomor antrean " << nomor << " berhasil ditambahkan.\n";
    }
}

// 4. Fungsi memanggil/mengurangi antrean (Dequeue)
void Dequeue() {
    if (isEmpty()) {
        cout << "\n[Peringatan] Antrean kosong! Tidak ada pengunjung yang bisa dipanggil.\n";
    } else {
        cout << "\n[Panggilan] Loket memanggil nomor antrean: " << q.nomorAntrean[q.front] << "\n";
        q.front++;
        
        // Reset index jika semua antrean sudah diproses agar memori bisa digunakan kembali
        if (q.front > q.rear) {
            q.front = -1;
            q.rear = -1;
        }
    }
}

// 5. Fungsi melihat antrean terdepan tanpa menghapusnya (Peek)
void Peek() {
    if (isEmpty()) {
        cout << "\n[Info] Tidak ada antrean saat ini.\n";
    } else {
        cout << "\n[Info] Antrean terdepan saat ini: Nomor " << q.nomorAntrean[q.front] << "\n";
    }
}

// 6. Fungsi mendapatkan jumlah antrean yang sedang menunggu (Size)
int Size() {
    if (isEmpty()) {
        return 0;
    }
    return q.rear - q.front + 1;
}

// 7. Fungsi menampilkan seluruh isi antrean (Display)
void Display() {
    if (isEmpty()) {
        cout << "\n=========================================\n";
        cout << "       DAFTAR ANTREAN SAAT INI\n";
        cout << "=========================================\n";
        cout << "  [ Antrean Kosong ]\n";
        cout << "=========================================\n";
    } else {
        cout << "\n=========================================\n";
        cout << "       DAFTAR ANTREAN SAAT INI\n";
        cout << "=========================================\n";
        cout << "  Depan -> ";
        for (int i = q.front; i <= q.rear; i++) {
            cout << "[" << q.nomorAntrean[i] << "] ";
        }
        cout << "<- Belakang\n";
        cout << "=========================================\n";
        cout << "  Total dalam antrean: " << Size() << " orang\n";
        cout << "=========================================\n";
    }
}

// Program Utama (Menu Interaktif Loket)
int main() {
    int pilihan, nomorGenerator = 1001; // Memulai nomor antrean dari 1001

    do {
        system("clear"); // Gunakan system("cls") jika kamu menggunakan Windows
        cout << "=== SISTEM ANTREAN DIGITAL LOKET LAYANAN PUBLIK RADITIYA GIRI PASHA===\n";
        cout << "1. Ambil Nomor Antrean (Enqueue)\n";
        cout << "2. Panggil Antrean Berikutnya (Dequeue)\n";
        cout << "3. Lihat Antrean Terdepan (Peek)\n";
        cout << "4. Cek Status Antrean (Size & IsEmpty/IsFull)\n";
        cout << "5. Cetak Semua Antrean (Display)\n";
        cout << "6. Keluar Program\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                Enqueue(nomorGenerator++);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Peek();
                break;
            case 4:
                if (isFull()) cout << "\nStatus: Antrean PENUH.\n";
                else if (isEmpty()) cout << "\nStatus: Antrean KOSONG.\n";
                else cout << "\nStatus: Antrean tersedia. Jumlah antrean saat ini: " << Size() << " orang.\n";
                break;
            case 5:
                Display();
                break;
            case 6:
                cout << "\nTerima kasih! Program selesai.\n";
                break;
            default:
                cout << "\nPilihan menu tidak valid!\n";
        }
        
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get(); 

    } while (pilihan != 6);

    return 0;
}
