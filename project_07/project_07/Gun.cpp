#include "Gun.h"

	void Gun::attack() {
		cout << "�ѽ��!" << endl;
	}
	int Gun::getpower()
	{
		return power;
	}
	void Gun::setNPA() {
		this->NPA += 1;
	}
	void Gun::useNPA() {
		this->NPA -= 1;
	}
	int Gun::getNPA()
	{
		return NPA;
	}
