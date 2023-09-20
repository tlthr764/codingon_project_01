#include "Character.h"

	Character::Character(string name) {
		this->name = name;
	}

	void Character::attack(int power) {
		monsterhp -= power;
		if (monsterhp <= 0) {
			cout << "�ҽ��� ������� ����� ������ �޾� �������ϴ�..." << endl;
			cout << "������� �ٽ� �����մϴ�..." << endl;
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