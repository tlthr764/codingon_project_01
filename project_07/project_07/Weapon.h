#pragma once
#include <iostream>

using namespace std;

class Weapon {
protected:
	int power = 0;
	int NPA = 0;
public:
	virtual void attack() = 0;
	virtual int getpower() = 0;
	virtual void setNPA() = 0;
	virtual void useNPA() = 0;
	virtual int getNPA() = 0;
};