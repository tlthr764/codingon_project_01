// 게임 만들기
#include <iostream>
#include "Weapon.h"
#include "Gun.h"
#include "Sword.h"
#include "Character.h"

using namespace std;

int main() {
	// 게임 시작 버튼 while문
	cout << " ☆★☆★☆★☆★☆★☆ Play Practice Game ★☆★☆★☆★☆★☆★ " << endl << endl;
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
	Weapon* gg = &G1;
	Weapon* ss = &S1;


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
				P1.pickup_item(gg);
				cout << "총을 획득했습니다." << endl << "현재 총의 개수 : " << G1.getNPA() << endl;
			}
			else if (option == 2) {
				P1.pickup_item(ss);
				cout << "검을 획득했습니다." << endl << "현재 검의 개수 : " << S1.howmany() << endl;
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
				if (G1.getNPA() > 0) {
					cout << "샌드백을 공격합니다!" << "총의 공격력 : " << G1.getpower() << endl;
					G1.attack();
					P1.attack(G1.getpower());
					P1.use_item(gg);
					cout << "샌드백의 남은 체력 : " << P1.getmonster() << endl << " 남은 공격 횟수 : " << G1.getNPA() << endl;
				}
				else {
					cout << "총이 없습니다..." << endl;
				}
			}
			else if (option == 2) {
				if (S1.getNPA() > 0) {
					cout << "샌드백을 공격합니다!" << "검의 공격력 : " << S1.getpower() << endl;
					S1.attack();
					P1.attack(S1.getpower());
					P1.use_item(ss);
					cout << "샌드백의 남은 체력 : " << P1.getmonster() << endl << " 남은 공격 횟수 : " << S1.getNPA() << endl;
				}
				else {
					cout << "검이 없습니다..." << endl;
				}
			}
			break;
		case 5:
			cout << "********** 캐릭터 정보 **********" << endl;
			cout << "이름 : " << P1.getname() << endl << "레벨 : " << P1.getlevel() << endl << "총 갯수 : " << G1.getNPA() << endl << "\
검 갯수 : " << S1.howmany() << endl;
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