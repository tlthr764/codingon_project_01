#include "Gun.h"

	void Gun::attack() {
		cout << "ÃÑ½î±â!" << endl;
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
