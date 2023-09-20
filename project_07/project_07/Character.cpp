#include "Character.h"

	Character::Character(string name) {
		this->name = name;
	}
	void Character::attack(int power) {
		monsterHP -= power;
		if (monsterHP > 0) {
			cout << "샌드백의 남은 체력 : " << monsterHP << endl;
		}
		else {
			cout << "불쌍한 샌드백이 당신의 공격을 받아 터졌습니다..." << endl;
			cout << "샌드백을 다시 리필합니다..." << endl;
			monsterHP = 200;
		}
	}
	int Character::getgunNum()
	{
		return gunChara.gunNum;
	}
	int Character::getswordNum()
	{
		return swordChara.swordNum;
	}
	int Character::howmany() {
		if (getswordNum() % 3 == 0) {
			return getswordNum() / 3;
		}
		else {
			return getswordNum() / 3 + 1;
		}
	}
	string Character::setname(string n) {
		return name = n;
	}
	int Character::level_up() {
		return ++level;
	}
	string Character::getname() {
		return name;
	}
	int Character::getlevel() {
		return level;
	}
	int Character::getmonster() {
		return monsterHP;
	}
	int Character::pickup_item(int option) {
		if (option == 1) {
			gunChara.gunNum += 1;
			return gunChara.getgunNum();
		}
		else {
			swordChara.swordNum += 3;
			return swordChara.getswordNum();
		}
	}
	int Character::use_item(int option) {
		if (option == 1) {
			if (gunChara.gunNum > 0) {
				return --gunChara.gunNum;
			}
		}
		else {
			if (swordChara.swordNum > 0) {
				return --swordChara.swordNum;
			}
		}
	}
