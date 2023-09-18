// 야구 게임
#include <iostream>
#include <random>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	// 게임 시작
	cout << "************ Play Baseball ************" << endl << endl;
	while (1) {
		string p;
		cout << "p를 누르면 게임 시작 ";
		cin >> p;
		if (p.compare("p") == 0) {
			break;
		}
	}
	cout << "→ 게임을 시작합니다!" << endl << endl;

	//유저 변수 정의
	vector<int> user(3,0);
	vector<bool> u_check(10,false);
	//컴퓨터 변수 정의
	vector<int> com(3, 0);
	vector<bool> c_check(10, false);
	mt19937_64 random_num(time(nullptr));
	uniform_int_distribution<__int64> com_num(1, 9);
	// 루프 관련 변수 정의
	bool f_loop = true; //전체 루프 탈출 변수
	bool f_check = true;//입력 루프 탈출 변수
	int num = 0; //입력값
	
	// 전체 루프
	while (f_loop==true) {
		// 숫자 입력 루프
		while (f_check == true) {		
			u_check.clear();
			u_check.resize(10);
			user.clear();
			user.resize(3);//벡터 초기화

			cout << "1과 9 사이의 숫자 3개를 입력하세요 (그 외의 숫자 : 종료)" << endl;
			// 숫자 입력 받는 for문
			for (int i = 0; i < 3; i++) {
				cin >> num;
				if (num > 0 && num < 10) { // 1~9 입력
					user[i] = num;
					u_check[num] = true;
				}
				// 범위 밖 숫자 입력 
				else {
					cout << "※ 안내 : 범위 외 숫자 입력!" << endl;
					f_check = false;
					f_loop = false;
				}			
			}

			// 중복 찾기 if 문
			if (f_loop == true) {
				int count = 0;
				for (int i = 0; i < 10; i++) {
					if (u_check[i] == true) { 
						count++; // 체크의 원소 갯수 카운트
					}
				}
				// 중복이 아닌 경우
				if (count == 3) {
					f_check = false; //루프 탈출
				}
				// 중복인 경우
				else {
					cout << "중복 입력! 다시 입력해주세요." << endl;
				}
			}
		}

		// 중복과 범위 필터링 조건문
		if (f_loop == true && f_check == false) {
			c_check.clear();
			c_check.resize(10);
			com.clear();
			com.resize(3);//벡터 초기화

			// 컴퓨터 난수 생성
			int cc = 0;
			for (int i = 0; i < 3; i++) {
				do {
					cc = com_num(random_num);
				} while (c_check[cc] == true);
				com[i]=cc;
				c_check[cc] = true;
			}
			// 컴퓨터 숫자 출력
			for (int i = 0; i < 3; i++) {
				cout << com[i] << setw(2);
			}
			cout << "  <------------- Target" << endl;

			// 스트라이크 볼 판별 다중 for문
			int strike = 0;
			int ball = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (user[i] == com[j]) {
						if (i == j) {
							strike++;
						}
						else {
							ball++;
						}
					}
				}
			}
			// 결과 출력
			if (strike == 3) {
				cout << strike << " 스트라이크!!!" << endl;
				cout << "************** 승리 **************" << endl << endl;
				f_loop = false;
				break;
			}
			else {
				cout << "스트라이크 : " << strike << setw(3) << endl;
				cout << "볼 : " << ball << setw(3) << endl;
			}
		}
		f_check = true;
	}
	cout << "게임을 종료합니다..." << endl;
}
