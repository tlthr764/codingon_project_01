// ���� �����
#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
protected :
	double x = result;
	double y = 0;
	static double result;
public:
	explicit Calculator(double i) : y(i) {}
	Calculator(double i, double j) : x(i), y(j) {}
	virtual double math() {
		return 0;
	}
};
class Add : public Calculator {
public :
	Add(double i, double j) : Calculator(i,j) {}
	explicit Add(double i) : Calculator(i) {}

	double math() {
		return result = x + y;
	}
};
class Sub : public Calculator {
public:
	Sub(double i, double j) : Calculator(i, j) {}
	explicit Sub(double i) : Calculator(i) {}

	double math() {
		return result = x - y;
	}
};
class Product : public Calculator {
public:
	Product(double i, double j) : Calculator(i, j) {}
	explicit Product(double i) : Calculator(i) {}

	double math() {
		return result = x * y;
	}
};
class Divided : public Calculator {
public:
	Divided(double i, double j) : Calculator(i, j) {}
	explicit Divided(double i) : Calculator(i) {}

	double math() {
		return result = x / y;
	}
};

double Calculator::result = 0; // ���� ���� �ʱ�ȭ

int main() {
	double a = 0, b = 0;
	string element = "";
	string input = "";
	cout << " +-*/ ��Ģ���� ���� /*-+ " << endl << endl;

	while (1) {
		if (input != "Y") {
			cout << "���ڸ� �Է����ּ��� : ";
			cin >> a;
			cout << "�����ڸ� �Է����ּ��� : ";
			cin >> element;
			cout << "���ڸ� �Է����ּ��� : ";
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
				cout << "��� : " << pp->math() << endl;
			}
			else if (element == "-") {
				cout << "��� : " << ss->math() << endl;
			}
			else if (element == "*") {
				cout << "��� : " << mm->math() << endl;
			}
			else if (element == "/") {
				cout << "��� : " << dd->math() << endl;
			}
			else {
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���..." << endl;
			}
		}

		cout << "---------------------------------------" << endl;
		cout << "Y : ���, AC : �ʱ�ȭ, EXIT : ����   ";
		cin >> input;
		if (input == "EXIT") {
			break;
		}
		else if (input == "AC") {
			continue;
		}
		else if (input == "Y") {
	
			cout << "�����ڸ� �Է����ּ��� : ";
			cin >> element;
			cout << "���ڸ� �Է����ּ��� : ";
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
				cout << "��� : " << pp2->math() << endl;
			}
			else if (element == "-") {
				cout << "��� : " << ss2->math() << endl;
			}
			else if (element == "*") {
				cout << "��� : " << mm2->math() << endl;
			}
			else if (element == "/") {
				cout << "��� : " << dd2->math() << endl;
			}
			else {
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���..." << endl;
			}
		}
		else {
			cout << "�� ���� : �߸��� �Է��̹Ƿ� ��갪�� �ʱ�ȭ�˴ϴ�!" << endl;
		}
	}
}
