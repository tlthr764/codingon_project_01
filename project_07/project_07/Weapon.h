#pragma once
#include <iostream>

using namespace std;

class Weapon {
public:
	virtual void attack() = 0;
	virtual int getpower() = 0;
};
