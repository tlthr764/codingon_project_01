#include "Character.h"

	Character::Character(string name) {
		this->name = name;
	}

	void Character::attack(int power) {
		monsterhp -= power;
		if (monsterhp <= 0) {
			cout << "불쌍한 샌드백이 당신의 공격을 받아 터졌습니다..." << endl;
			cout << "샌드백을 다시 리필합니다..." << endl;
			monsterhp = 100;
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
		return monsterhp;
	}
	void Character::pickup_item(Weapon* pick) {
		pick->setNPA();
	}
	void Character::use_item(Weapon* use) {
		use->useNPA();
	}