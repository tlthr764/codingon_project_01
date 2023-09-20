#pragma once
#include "Weapon.h"

class Gun : public Weapon {
public:
	int power = 10;
	int NPA = 0;

	void attack();
	int getpower();
	void setNPA();
	void useNPA();
	int getNPA();
	
};