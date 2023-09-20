#pragma once
#include "Weapon.h"



class Character {
	string name = "";
	int monsterhp = 100;
	int level = 1;

public:
	Character(string name);

	void attack(int power);
	string setname(string n);
	int level_up();
	string getname();
	int getlevel();
	int getmonster();
	void pickup_item(Weapon* pick);
	void use_item(Weapon* use);
};
