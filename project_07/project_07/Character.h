#pragma once
#include <iostream>
#include "Weapon.h"
#include "Gun.h"
#include "Sword.h"

using namespace std;

class Character {
	string name = "";
	int monsterHP = 100;
	int level = 1;

public:
	Character(string name);
	Gun gunChara;
	Sword swordChara;

	void attack(int power);
	int getgunNum();
	int getswordNum();
	int howmany();
	string setname(string n);
	int level_up();
	string getname();
	int getlevel();
	int getmonster();
	int pickup_item(int option);
	int use_item(int option);
};