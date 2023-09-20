#include "Sword.h"


	void Sword::attack() {
		cout << "Âî¸£±â!" << endl;
	}
	int Sword::getpower()
	{
		return power;
	}
	int Sword::getswordNum()
	{
		return swordNum;
	}
	int Sword::howmany() {
		if (getswordNum() % 3 == 0) {
			return getswordNum() / 3;
		}
		else {
			return getswordNum() / 3 + 1;
		}
	}
