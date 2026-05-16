#include <iostream>
using namespace std;

class hewan{
	public:
		void bersuara(){
			cout << "Making Sound..." << endl;
		}
};

class bebek : hewan{
	public:
		
		void bersuara(){
			cout << "wek" << endl;
		}
};

int main (){
	bebek bebek1;
	bebek *bebek2 = new bebek();
	
	bebek1.bersuara();
	bebek2->bersuara();
	
	delete bebek2;	
	
	return 0;
}
