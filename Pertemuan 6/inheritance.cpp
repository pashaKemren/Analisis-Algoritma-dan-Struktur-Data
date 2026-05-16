#include <iostream>
using namespace std;

class Character {
	protected:
		int hp;
		int dmg;
		int exp;
		
	public:
		void setdmg(int dmg) {
			this -> dmg = dmg;
		}
		
		int getdmg() {
			return this -> dmg;
		}
};

class warrior : public Character {
	public:
		string nickname;
		
		void serang() {
			cout << "-HP" << this->dmg << endl;
		}
};

int main() {
	warrior player1;
	
	//input nickname
	cout << "masukan nickname:";
	cin >> player1.nickname;
	
	//output nickname
	cout << "nickname dari player adalah:" << player1.nickname << endl;
	
	//memasukan damage
	int dmg = 0;
	cout << "masukan damage dari character:";
	cin >> dmg;
	player1.setdmg(dmg);
	
	//player menyerang
	player1.serang();
	
	return 0;
	
	
	
	
}
