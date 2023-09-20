#pragma once
#include <iostream>
#include "Weapon.h"

using namespace std;

class Sword : public Weapon {
public:
	int power = 5;
	int swordNum = 0;

	void attack();
	int getpower();
	int getswordNum();
	int howmany();
};