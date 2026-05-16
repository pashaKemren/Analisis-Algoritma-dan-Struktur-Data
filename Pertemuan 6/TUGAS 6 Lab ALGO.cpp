#include <iostream>
#include <string>

using namespace std;

// Parent Class
class Mahasiswa {
protected:
    string nama;
    string nim;
    string jurusan;
    int semester;

public:
    // Setter
    void setNama(string n) {
        nama = n;
    }

    void setNim(string i) {
        nim = i;
    }

    void setJurusan(string j) {
        jurusan = j;
    }

    void setSemester(int s) {
        semester = s;
    }

    // Getter
    string getNama() {
        return nama;
    }

    string getNim() {
        return nim;
    }

    string getJurusan() {
        return jurusan;
    }

    int getSemester() {
        return semester;
    }

    // Method polymorphism
    virtual void tampilkanInfo() {
        cout << "Nama      : " << nama << endl;
        cout << "NIM       : " << nim << endl;
        cout << "Jurusan   : " << jurusan << endl;
        cout << "Semester  : " << semester << endl;
    }

    virtual void aktivitas() {
        cout << nama << " sedang belajar." << endl;
    }
};

// Child Class
class MahasiswaTI : public Mahasiswa {
private:
    string bahasaPemrograman;

public:
    void setBahasa(string b) {
        bahasaPemrograman = b;
    }

    string getBahasa() {
        return bahasaPemrograman;
    }

    // Overriding (Polymorphism)
    void tampilkanInfo() override {
        cout << "=== Data Mahasiswa TI ===" << endl;
        cout << "Nama      : " << nama << endl;
        cout << "NIM       : " << nim << endl;
        cout << "Jurusan   : " << jurusan << endl;
        cout << "Semester  : " << semester << endl;
        cout << "Bahasa    : " << bahasaPemrograman << endl;
    }

    void aktivitas() override {
        cout << nama << " sedang membuat program C++." << endl;
    }
};

int main() {

    MahasiswaTI mhs1;

    mhs1.setNama("Raditiya Giri Pasha");
    mhs1.setNim("252310014");
    mhs1.setJurusan("Teknologi Informasi");
    mhs1.setSemester(2);
    mhs1.setBahasa("C++");

    cout << endl;
    mhs1.tampilkanInfo();

    cout << endl;
    mhs1.aktivitas();

    return 0;
}
