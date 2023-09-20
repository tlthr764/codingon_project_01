#pragma once
#include <iostream>
#include "Weapon.h"

using namespace std;

class Gun : public Weapon {
public:
	int power = 10;
	int gunNum = 0;

	void attack();
	int getpower();
	int getgunNum();
};