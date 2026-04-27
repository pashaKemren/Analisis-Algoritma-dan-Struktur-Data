#include <iostream>
using namespace std;

class radit{
	public:
		radit(){
			cout << "Sedia barang di toko radit" << endl;
		}
		
		~radit(){
			cout << "Barang sudah kosong" << endl;
		}
};

int main(){
	cout << "lagi di cari bentar ye" << endl;
	radit ganz;
	cout << endl << "oke aman ye" << endl;
}
