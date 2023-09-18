// 랜덤 숫자 맞추기
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
	//사용자 변수 정의
	vector<int> user;
	int user_num = 0;
	int user_check[26] = { 0, };
	//유저 변수 정의
	vector<int> computer;
	mt19937_64 com_random(std::time(nullptr));
	uniform_int_distribution<__int64> com_num(1, 25);
	int com_check[26] = { 0, };

	//본문 시작
	cout << "& 랜덤 숫자 맞추기 (1~25까지의 숫자만 입력이 가능합니다) &" << endl;
	//숫자 입력 while문
	int i= 0; // 루프 탈출 변수 정의
	while (i<6) {
			cout << i + 1 << " 번째 번호를 입력하세요 : ";
			cin >> user_num; //숫자 입력

			// 범위 판별 if문
			if ((user_num > 0 && user_num < 26) && (user_check[user_num] == 0)) {
				user.push_back(user_num);
				user_check[user_num] = 1;//사용자 벡터에 숫자 입력
				i++;
			}
			else if (user_check[user_num] == 1) {
				cout << "중복된 숫자입니다! 새로운 숫자를 입력해주세요." << endl;
			}
			else  {
				cout << "잘못된 입력입니다! 1~25까지의 숫자를 입력하세요." << endl;
			}
	}

	// 컴퓨터 숫자 입력 for문 
	int cc = 0;
	for (int i = 0; i < 6; i++) {
		do {
			cc = com_num(com_random); 
		} while (com_check[cc] == 1); // do while문
		computer.insert(computer.begin() + i, cc);
		com_check[cc] = 1; //컴퓨터 벡터에 숫자 입력
	}

	// 당첨번호 공개 for문
	cout << "당첨번호 공개!" << endl;
	for (int i = 0; i < 6; i++) {
		cout << computer.at(i) << " ";
	}
	cout << endl;
	cout << "당신의 등수는 과연 몇등일까요?" << endl << "--------------------------------" << endl;

	// 배열 비교 for문
	int count = 7;
	for (int i : user){
		if (user_check[i] == com_check[i]) {
			count--;
			}
	}
	cout << " → " << count << " 등 입니다!";
}