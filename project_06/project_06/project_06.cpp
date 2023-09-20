// 계산기 만들기
#include <iostream>
#include <cmath>

using namespace std;

class Calculator { // 연산 클래스
protected :
	double x = result; // x값에 정적 변수 대입
	double y = 0;
	static double result; // static 필드
public:
	explicit Calculator(double i) : y(i) {} // case) Y일때 예외 생성자
	Calculator(double i, double j) : x(i), y(j) {} // 생성자
	virtual double math() { // 가상함수
		return 0;
	}
};
class Add : public Calculator { // 덧셈 클래스
public :
	Add(double i, double j) : Calculator(i,j) {}
	explicit Add(double i) : Calculator(i) {}

	double math() {
		return result = x + y;
	}
};
class Sub : public Calculator { // 뺄셈 클래스
public:
	Sub(double i, double j) : Calculator(i, j) {}
	explicit Sub(double i) : Calculator(i) {}

	double math() {
		return result = x - y;
	}
};
class Product : public Calculator { // 곱셈 클래스
public:
	Product(double i, double j) : Calculator(i, j) {}
	explicit Product(double i) : Calculator(i) {}

	double math() {
		return result = x * y;
	}
};
class Divided : public Calculator { // 나눗셈 클래스
public:
	Divided(double i, double j) : Calculator(i, j) {}
	explicit Divided(double i) : Calculator(i) {}

	double math() {
		return result = x / y;
	}
};

double Calculator::result = 0; // 정적 변수 초기화

int main() {
	//변수 정의
	double a = 0, b = 0;
	string element = "";
	string input = "";
	cout << " +-*/ 사칙연산 계산기 /*-+ " << endl << endl;

	// 사칙 연산 while문
	while (1) {
		if (input != "Y") {
			cout << "숫자를 입력해주세요 : ";
			cin >> a;
			cout << "연산자를 입력해주세요 : ";
			cin >> element;
			cout << "숫자를 입력해주세요 : ";
			cin >> b;
			
			Add plus(a,b);
			Sub minus(a,b);
			Product mult(a,b);
			Divided divid(a,b);

			Calculator* pp = &plus;
			Calculator* ss = &minus;
			Calculator* mm = &mult;
			Calculator* dd = &divid;

			if (element == "+") {
				cout << "결과 : " << pp->math() << endl;
			}
			else if (element == "-") {
				cout << "결과 : " << ss->math() << endl;
			}
			else if (element == "*") {
				cout << "결과 : " << mm->math() << endl;
			}
			else if (element == "/") {
				cout << "결과 : " << dd->math() << endl;
			}
			else {
				cout << "잘못된 입력입니다. 다시 입력해주세요..." << endl;
			}
		}

		cout << "---------------------------------------" << endl;
		cout << "Y : 계속, AC : 초기화, EXIT : 종료   ";
		cin >> input;
		if (input == "EXIT") { // EXIT일때 if문
			break; // 루프 탈출
		}
		else if (input == "AC") { // AC일때 if문
			continue;
		}
		else if (input == "Y") { // Y일때 if문
	
			cout << "연산자를 입력해주세요 : ";
			cin >> element;
			cout << "숫자를 입력해주세요 : ";
			cin >> b;
			
			Add plus2(b);
			Sub minus2(b);
			Product mult2(b);
			Divided divid2(b);

			Calculator* pp2 = &plus2;
			Calculator* ss2 = &minus2;
			Calculator* mm2 = &mult2;
			Calculator* dd2 = &divid2;

			if (element == "+") {
				cout << "결과 : " << pp2->math() << endl;
			}
			else if (element == "-") {
				cout << "결과 : " << ss2->math() << endl;
			}
			else if (element == "*") {
				cout << "결과 : " << mm2->math() << endl;
			}
			else if (element == "/") {
				cout << "결과 : " << dd2->math() << endl;
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
