// 게임 만들기
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
		cout << "→ p를 눌러서 게임을 시작 ";
		cin >> start;
		if (start.compare("p") == 0) {
			break;
		}
	}
	cout << endl;

	cout << "→ PPG를 시작합니다!" << endl << endl;
	cout << "→ 캐릭터를 생성합니다. 캐릭터의 이름을 입력해주세요." << endl;
	string name1 = "";
	cin >> name1;
	Character P1(name1);
	Gun G1;
	Sword S1;

	cout << "→ " << name1 << "님의 게임이 시작됩니다..." << endl << endl;
	cout << "********** 조작 방법 **********" << endl;
	cout << "→ 1 : 캐릭터 이름 변경\n" << "→ 2 : 레벨 업\n" << "→ 3 : 무기 획득\n" << "→ 4 : 공격하기\n" << "→ 5 : 캐릭터 정보 확인\n" << "→ 6 : 조작 방법 다시보기\n" << "→ 0 : 게임 종료\n";
	cout << "*******************************" << endl;

	bool system = true;
	int num = 0;
	int option = 0;
	while (system == true) {
		cout << "숫자를 입력하여 캐릭터를 조작하세요 : ";
		cin >> num;
		string newname = "";
		switch (num)
		{
		case 0:
			cout << "게임을 종료합니다..." << endl;
			system = false;
			break;
		case 1:
			cout << "Player1의 새 이름을 입력해주세요." << endl;
			cin >> newname;
			P1.setname(newname);
			cout << "Player1의 이름이 변경되었습니다!" << endl << "Player1 이름 : " << P1.getname() << endl;
			break;
		case 2:
			P1.level_up();
			cout << "레벨 업!" << endl << P1.getname() << "님의 현재 레벨 : " << P1.getlevel() << endl;
			break;
		case 3:
			while (1) {
				cout << "획득할 무기를 선택하세요 (총 : 1, 검 : 2) → ";
				cin >> option;
				if (option == 1 || option == 2) {
					break;
				}
				else {
					cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
				}
			}
			if (option == 1) {
				cout << "총을 획득했습니다." << endl << "현재 총의 개수 : " << P1.pickup_item(option) << endl;
			}
			else if (option == 2) {
				P1.pickup_item(option);
				cout << "검을 획득했습니다." << endl << "현재 검의 개수 : " << P1.howmany() << endl;
			}
			break;
		case 4:
			cout << "-------------- 공 격 하 기 --------------" << endl;
			while (1) {
				cout << "공격할 무기를 선택하세요 (총 : 1, 검 : 2) → ";
				cin >> option;
				if (option == 1 || option == 2) {
					break;
				}
				else {
					cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
				}
			}
			if (option == 1) {
				if (P1.getgunNum() > 0) {
					cout << "샌드백을 공격합니다!" << "검의 공격력 : " << G1.getpower() << endl;
					G1.attack();
					P1.attack(G1.getpower());
					cout << "샌드백의 남은 체력 : " << P1.getmonster() << endl << " 남은 공격 횟수 : " << P1.use_item(option) << endl;
				}
				else {
					cout << "총이 없습니다..." << endl;
				}
			}
			else if (option == 2) {
				if (P1.getswordNum() > 0) {
					cout << "샌드백을 공격합니다!" << "검의 공격력 : " << S1.getpower() << endl;
					S1.attack();
					P1.attack(S1.getpower());
					cout << "샌드백의 남은 체력 : " << P1.getmonster() << endl << " 남은 공격 횟수 : " << P1.use_item(option) << endl;
				}
				else {
					cout << "검이 없습니다..." << endl;
				}
			}
			break;
		case 5:
			cout << "********** 캐릭터 정보 **********" << endl;
			cout << "이름 : " << P1.getname() << endl << "레벨 : " << P1.getlevel() << endl << "총 갯수 : " << P1.getgunNum() << endl << "\
검 갯수 : " << P1.howmany() << endl;
			cout << "*********************************" << endl;
			break;
		case 6:
			cout << "********** 조작 방법 **********" << endl;
			cout << "→ 1 : 캐릭터 이름 변경\n" << "→ 2 : 레벨 업\n" << "→ 3 : 무기 변경\n" << "→ 4 : 공격하기\n" << "→ 5 : 캐릭터 정보 확인\n" << "→ 6 : 조작 방법 다시보기\n" << "→ 0 : 게임 종료\n";
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
//		cout << "총쏘기!" << endl;
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
//		cout << "찌르기!" << endl;
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
//			cout << "샌드백의 남은 체력 : " << monsterHP << endl;
//		}
//		else {
//			cout << "불쌍한 샌드백이 당신의 공격을 받아 터졌습니다..." << endl;
//			cout << "샌드백을 다시 리필합니다..." << endl;
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