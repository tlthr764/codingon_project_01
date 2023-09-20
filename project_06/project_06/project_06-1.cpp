// 계산기 만들기
#include <iostream>

using namespace std;

class Calculator {
	double x = result;
	double y = 0;
	static double result;
public :

	explicit Calculator(double i) : y(i){}
	Calculator(static double i, double j) : x(i), y(j) {}
	double plus() {
		return result = x + y;
	}
	double minus() {
		return result = x - y;
	}
	double multiply() {
		return result = x * y;
	}
	double division() {
		return result = x / y;
	}
};
double Calculator::result = 0;

int main() {
	int a = 0, b = 0;
	string element = "";
	string input = "";
	cout << " +-*/ 사칙연산 계산기 /*-+ " << endl << endl;

	while (1) {
		if (input != "Y") {
			cout << "숫자를 입력해주세요 : ";
			cin >> a;
			cout << "연산자를 입력해주세요 : ";
			cin >> element;
			cout << "숫자를 입력해주세요 : ";
			cin >> b;
			Calculator cal(a, b);
			if (element == "+") {
				cout << "결과 : " << cal.plus() << endl;
			}
			else if (element == "-") {
				cout << "결과 : " << cal.minus() << endl;
			}
			else if (element == "*") {
				cout << "결과 : " << cal.multiply() << endl;
			}
			else if (element == "/") {
				cout << "결과 : " << cal.division() << endl;
			}
			else {
				cout << "잘못된 입력입니다. 다시 입력해주세요..." << endl;
			}
		}
		
		cout << "---------------------------------------" << endl;
		cout << "Y : 계속, AC : 초기화, EXIT : 종료   ";
		cin >> input;
		if (input == "EXIT") {
			break;
		}
		else if (input == "AC") {
			continue;
		}
		else if (input == "Y") {
			cout << "연산자를 입력해주세요 : ";
			cin >> element;
			cout << "숫자를 입력해주세요 : ";
			cin >> b;
			Calculator cal2(b);
			if (element == "+") {
				cout << "결과 : " << cal2.plus() << endl;
			}
			else if (element == "-") {
				cout << "결과 : " << cal2.minus() << endl;
			}
			else if (element == "*") {
				cout << "결과 : " << cal2.multiply() << endl;
			}
			else if (element == "/") {
				cout << "결과 : " << cal2.division() << endl;
			}
			else {
				cout << "잘못된 입력입니다. 다시 입력해주세요..." << endl;
			}
		}
		else {
			cout << "※ 오류 : 잘못된 입력이므로 계산값이 초기화됩니다!" << endl;
		}
	}
}
