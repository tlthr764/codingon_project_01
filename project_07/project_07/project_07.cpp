// ���� �����
#include <iostream>
#include "Weapon.h"
#include "Gun.h"
#include "Sword.h"
#include "Character.h"

using namespace std;

int main() {

	cout << "      Play Practice Game      " << endl << endl;
	while (1) {
		string start;
		cout << "�� p�� ������ ������ ���� ";
		cin >> start;
		if (start.compare("p") == 0) {
			break;
		}
	}
	cout << endl;

	cout << "�� PPG�� �����մϴ�!" << endl << endl;
	cout << "�� ĳ���͸� �����մϴ�. ĳ������ �̸��� �Է����ּ���." << endl;
	string name1 = "";
	cin >> name1;
	Character P1(name1);
	Gun G1;
	Sword S1;

	cout << "�� " << name1 << "���� ������ ���۵˴ϴ�..." << endl << endl;
	cout << "********** ���� ��� **********" << endl;
	cout << "�� 1 : ĳ���� �̸� ����\n" << "�� 2 : ���� ��\n" << "�� 3 : ���� ȹ��\n" << "�� 4 : �����ϱ�\n" << "�� 5 : ĳ���� ���� Ȯ��\n" << "�� 6 : ���� ��� �ٽú���\n" << "�� 0 : ���� ����\n";
	cout << "*******************************" << endl;

	bool system = true;
	int num = 0;
	int option = 0;
	while (system == true) {
		cout << "���ڸ� �Է��Ͽ� ĳ���͸� �����ϼ��� : ";
		cin >> num;
		string newname = "";
		switch (num)
		{
		case 0:
			cout << "������ �����մϴ�..." << endl;
			system = false;
			break;
		case 1:
			cout << "Player1�� �� �̸��� �Է����ּ���." << endl;
			cin >> newname;
			P1.setname(newname);
			cout << "Player1�� �̸��� ����Ǿ����ϴ�!" << endl << "Player1 �̸� : " << P1.getname() << endl;
			break;
		case 2:
			P1.level_up();
			cout << "���� ��!" << endl << P1.getname() << "���� ���� ���� : " << P1.getlevel() << endl;
			break;
		case 3:
			while (1) {
				cout << "ȹ���� ���⸦ �����ϼ��� (�� : 1, �� : 2) �� ";
				cin >> option;
				if (option == 1 || option == 2) {
					break;
				}
				else {
					cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
				}
			}
			if (option == 1) {
				cout << "���� ȹ���߽��ϴ�." << endl << "���� ���� ���� : " << P1.pickup_item(option) << endl;
			}
			else if (option == 2) {
				P1.pickup_item(option);
				cout << "���� ȹ���߽��ϴ�." << endl << "���� ���� ���� : " << P1.howmany() << endl;
			}
			break;
		case 4:
			cout << "-------------- �� �� �� �� --------------" << endl;
			while (1) {
				cout << "������ ���⸦ �����ϼ��� (�� : 1, �� : 2) �� ";
				cin >> option;
				if (option == 1 || option == 2) {
					break;
				}
				else {
					cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
				}
			}
			if (option == 1) {
				if (P1.getgunNum() > 0) {
					cout << "������� �����մϴ�!" << "���� ���ݷ� : " << G1.getpower() << endl;
					G1.attack();
					P1.attack(G1.getpower());
					cout << "������� ���� ü�� : " << P1.getmonster() << endl << " ���� ���� Ƚ�� : " << P1.use_item(option) << endl;
				}
				else {
					cout << "���� �����ϴ�..." << endl;
				}
			}
			else if (option == 2) {
				if (P1.getswordNum() > 0) {
					cout << "������� �����մϴ�!" << "���� ���ݷ� : " << S1.getpower() << endl;
					S1.attack();
					P1.attack(S1.getpower());
					cout << "������� ���� ü�� : " << P1.getmonster() << endl << " ���� ���� Ƚ�� : " << P1.use_item(option) << endl;
				}
				else {
					cout << "���� �����ϴ�..." << endl;
				}
			}
			break;
		case 5:
			cout << "********** ĳ���� ���� **********" << endl;
			cout << "�̸� : " << P1.getname() << endl << "���� : " << P1.getlevel() << endl << "�� ���� : " << P1.getgunNum() << endl << "\
�� ���� : " << P1.howmany() << endl;
			cout << "*********************************" << endl;
			break;
		case 6:
			cout << "********** ���� ��� **********" << endl;
			cout << "�� 1 : ĳ���� �̸� ����\n" << "�� 2 : ���� ��\n" << "�� 3 : ���� ����\n" << "�� 4 : �����ϱ�\n" << "�� 5 : ĳ���� ���� Ȯ��\n" << "�� 6 : ���� ��� �ٽú���\n" << "�� 0 : ���� ����\n";
			cout << "*******************************" << endl;
			break;
		}
	}
}

//class Weapon {
//public:
//	virtual void attack() = 0;
//	virtual int getpower() = 0;
//};
//
//class Gun : public Weapon {
//public:
//	int power = 10;
//	int gunNum = 0;
//
//	void attack() {
//		cout << "�ѽ��!" << endl;
//	}
//	int getpower()
//	{
//		return power;
//	}
//	int getgunNum()
//	{
//		return gunNum;
//	}
//};
//
//class Sword : public Weapon {
//public:
//	int power = 5;
//	int swordNum=0;
//
//	void attack() {
//		cout << "���!" << endl;
//	}
//	int getpower()
//	{
//		return power;
//	}
//	int getswordNum()
//	{
//		return swordNum;
//	}
//	int howmany() {
//		if (getswordNum() % 3 == 0) {
//			return getswordNum() / 3;
//		}
//		else {
//			return getswordNum() / 3 + 1;
//		}
//	}
//};
//
//class Character {
//	string name = "";
//	int monsterHP = 100;
//	int level = 1;
//
//public:
//	Character(string name) {
//		this->name = name;
//	}
//
//	Gun gunChara;
//	Sword swordChara;
//
//	void attack(int power) {
//		monsterHP -= power;
//		if (monsterHP > 0) {
//			cout << "������� ���� ü�� : " << monsterHP << endl;
//		}
//		else {
//			cout << "�ҽ��� ������� ����� ������ �޾� �������ϴ�..." << endl;
//			cout << "������� �ٽ� �����մϴ�..." << endl;
//			monsterHP = 200;
//		}
//	}
//	int getgunNum()
//	{
//		return gunChara.gunNum;
//	}
//	int getswordNum()
//	{
//		return swordChara.swordNum;
//	}
//	int howmany() {
//		if (getswordNum() % 3 == 0) {
//			return getswordNum() / 3;
//		}
//		else {
//			return getswordNum() / 3 + 1;
//		}
//	}
//	string setname(string n) {
//		return name = n;
//	}
//	int level_up() {
//		return ++level;
//	}
//	string getname() {
//		return name;
//	}
//	int getlevel() {
//		return level;
//	}
//	int getmonster() {
//		return monsterHP;
//	}
//	int pickup_item(int option) {
//		if (option == 1) {
//			gunChara.gunNum += 1;
//			return gunChara.getgunNum();
//		}
//		else {
//			swordChara.swordNum += 3;
//			return swordChara.getswordNum();
//		}
//	}
//	int use_item(int option) {
//		if (option == 1) {
//			if (gunChara.gunNum > 0) {
//				return --gunChara.gunNum;
//			}
//		}
//		else {
//			if (swordChara.swordNum > 0) {
//				return --swordChara.swordNum;
//			}
//		}
//	}
//};