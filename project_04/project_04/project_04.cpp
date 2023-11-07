// 마방진 만들기
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	// 숫자 num 값 입력 받기
	int num = 0;
	cout << "홀수인 N으로 마방진 NxN을 만듭니다..." << endl;
	while (1) {
		cout << "자연수이자 홀수인 숫자를 입력하세요 : ";
		cin >> num;
		if (num > 0 && num % 2 == 1) {
			break;
		}
	}
	cout << endl;

	// 동적 배열 선언 & 할당
	int** arr = new int* [num];
	for (int i = 0; i < num; i++) {
		arr[i] = new int[num];
	}

	// 초기 배열 선언
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			arr[i][j] = 0; // 동적 배열 초기값 0
		}
	}

	// 원소 1의 위치
	int x = 0;
	int y = num / 2;
	int nn = num * num;
	arr[x][y] = 1;

	// 마방진 본문
	for (int i = 2; i < nn+1; i++) {
		int max = num - 1;

		// case1) 원소가 (min,max) 에 위치
		if ((x - 1) < 0 && (y + 1) > max) {
			x += 1;
		}

		// case2) 원소가 (min,y) 에 위치
		else if ((x - 1) < 0 && (y + 1) <= max) {
			if (arr[max][y + 1] == 0) {
				// 이동할 칸이 비어있을 때
				x = max;
				y += 1;
			}
			else {
				// 이동할 칸이 이미 채워져 있을 때
				x += 1;
			}
		}

		// case3) 원소가 (x,max) 에 위치
		else if ((x - 1) >= 0 && (y + 1) > max) {
			if (arr[x - 1][0] == 0) {
				// 이동할 칸이 비어있을 때
				x -= 1;
				y = 0;
			}
			else {
				// 이동할 칸이 이미 채워져 있을 때
				x += 1;
			}
		}
		// case3) 원소가 (x,y) 에 위치
		else {
			if (arr[x - 1][y + 1] == 0) {
				// 이동할 칸이 비어있을 때
				x -= 1;
				y += 1;
			}
			else {
				// 이동할 칸이 이미 채워져 있을 때
				x += 1;
			}
		}
		// 배열에 i값 삽입
		arr[x][y] = i;
	}

	// 마방진 출력
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
	
	
	// 동적 배열 해제 (반납)
	for (int i = 0; i < num; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}