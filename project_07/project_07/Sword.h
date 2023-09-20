#pragma once
#include "Weapon.h"

class Sword : public Weapon {
public:
	int power = 5;
	int NPA = 0;

	void attack();
	int getpower();
	void setNPA();
	void useNPA();
	int getNPA();
	int howmany();
};