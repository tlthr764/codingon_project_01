// 베스킨라빈스 31 게임
#include <iostream>
#include <vector>
#include <random>

using namespace std;


int main() {
	//컴퓨터 랜덤 숫자 정의
	mt19937_64 limit_1to3(time(nullptr));
	uniform_int_distribution<__int64> com_num(1, 3);
	//사용자 숫자 정의
	int user_num = 0;
	//베라31 배열 정의
	vector<int> br31;
	// while문 루프 탈출 변수 정의
	bool game_over = true;
	
	// 베라31 배열 숫자 삽입 for문
	for (int i = 0; i < 31; i++) {
		br31.push_back(i + 1);
	}

	// 게임 while문
	while (game_over) {
		//개수 입력 받기
		cout << "개수를 입력하세요 : ";
		cin >> user_num;
	
		// 사용자 숫자가 1~3 사이인지 판별 if문
		if (user_num > 0 && user_num < 4) {
			cout << "사용자가 부른 숫자!" << endl;
			for (int i = 0; i < user_num; i++) {
				cout << br31.at(0) << endl;
				br31.erase(br31.begin());
				if (br31.size() == 0) {
					cout << "당신의 패배..." << endl;
					game_over = false;
					break;
				}
			}
		}
		else {
			cout << "잘못된 입력입니다!" << endl << "1~3사이 숫자를 입력하세요." << endl;
		}
		// 사용자의 패배시 루프를 탈출하기 위한 if 문
		if (game_over == false) {
			break;
		}

		// 컴퓨터 숫자 입력 for문
		cout << "컴퓨터가 부른 숫자!" << endl;
		for (int i = 0; i < com_num(limit_1to3); i++) {
			cout << br31.at(0) << endl;
			br31.erase(br31.begin());
			if (br31.size() == 0) {
				cout << "당신의 승리!" << endl;
				game_over = false;
				break;
			}
		}
	}
}