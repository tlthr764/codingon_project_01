#include "Sword.h"

	void Sword::attack() {
		cout << "Âî¸£±â!" << endl;
	}
	int Sword::getpower()
	{
		return power;
	}
	void Sword::setNPA() {
		this->NPA += 3;
	}
	void Sword::useNPA() {
		this->NPA -= 1;
	}
	int Sword::getNPA()
	{
		return NPA;
	}
	int Sword::howmany() {
		if (getNPA() % 3 == 0) {
			return getNPA() / 3;
		}
		else {
			return getNPA() / 3 + 1;
		}
	}
