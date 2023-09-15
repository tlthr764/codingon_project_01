// 타임어택 끝말잇기 게임
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
	// 변수 정의
	string word = "";
	vector<string> word_list;
	int word_length = 0;
	int size =0;

	// 처음 시작문
	cout << "끝말잇기 게임을 시작합니다!" << endl;
	cout << "첫 단어를 입력하세요 : ";
	cin >> word;
	
	// 벡터에 시작 단어 삽입 및 변수값 입력
	word_list.push_back(word);
	word_length = word.size();
	size = word_list.size() - 1;
	cout << word << endl; // 첫 단어 출력
	clock_t startTime = clock(); // 시간 측정 시작

	while (1) {
		// 단어 입력 받기
		cout << "다음 단어를 입력하세요 : ";
		cin >> word;

		// 앞 단어 맨뒤글자와 입력 단어 맨앞글자 비교 if문
		while (1) {
			if (word[0] != word_list.at(size)[word_length - 1]) {
				cout << "잘못된 입력입니다!" << endl;
				cout << "다시 입력하세요 : ";
				cin >> word;
			}
			else {
				break;
			}
		}
		// 중복단어 판별 for문
		for (int i = 0; i < size + 1; i++) {
			while (word == word_list.at(i)) {
				cout << "중복된 단어입니다!" << endl;
				cout << "새로운 단어를 입력해주세요 : ";
				cin >> word;
			}
		}

		// 변수 재설정
		word_list.push_back(word);
		word_length = word.size();
		size = word_list.size() - 1;

		// 나왔던 단어 출력
		for (int i = 0; i < size; i++) {
			cout << word_list.at(i) << "->";
		}
		cout << word_list.at(size)<<endl;
		clock_t endTime = clock(); // 시간 측정 끝
		// 시간 초과 판별 if문
		if ((endTime - startTime) / CLOCKS_PER_SEC > 20) {
			cout << "타임 오버..." << endl;
			break;
		}
	}
	// 단어 개수 출력
	cout << "******* GAME OVER *******" << endl << "총 입력한 단어 개수 : " << word_list.size() << endl;
}