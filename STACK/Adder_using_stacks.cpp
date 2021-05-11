#include <iostream>
#include <stack>
using namespace std;

template<class T>
class stackcalc {

public:
	stackcalc() {};
	~stackcalc() {};
	void addProcess();
	void pushThis_2a(int num);
	void pushThis_2b(int num);
	void popResult();


private:
	stack<int>m_a;
	stack<int>m_b;
	stack<int>a;
	stack<int>b;
	int carry=0;
	int addElemet;
	stack<int>result;
};


template<class T>
void stackcalc<T>::pushThis_2b(int num) {
	//뒤집혀서 계산되는오류, 넣은값을 다시 스택하면 값역시 다시 뒤집혀 원하는 값이 나온다.
	while (num != 0){
		m_b.push(num % 10);
		num /= 10;
	}
	while (!m_b.empty()) {
		b.push(m_b.top());
		m_b.pop();
	}
}

template<class T>
void stackcalc<T>::pushThis_2a(int num) {
	while (num != 0){
		m_a.push(num % 10);
		num /= 10;
	}
	while (!m_a.empty()) {
		a.push(m_a.top());
		m_a.pop();
	}
}

template<class T>
void stackcalc<T>::addProcess() {
	while (a.empty() == false || b.empty() == false) {
		//자리수맞추기용
		if (a.empty() == true)a.push(0);
		if (b.empty() == true)b.push(0);
		addElemet = a.top() + b.top() + carry;
		a.pop();
		b.pop();
		carry = 0;
		if ((addElemet / 10) == true) {
			carry = 1;
			addElemet = addElemet - 10;
		}
		result.push(addElemet);
	}
}

template<class T>
void stackcalc<T>::popResult() {
	int digit;

	cout << "Result: ";
	while (result.empty() == false) {
		digit = result.top();
		cout << digit;
		result.pop();
	}
}

int main() {
	bool hello = 0;
initialize:
	stackcalc<int> opr;
	int number_a, number_b;
	bool re = 0;
	if (hello == 0) {
		cout << "-Stack을 이용한 정수간 덧셈 계산기 201721565손민우-\n";
		cout << "각 오퍼랜드값은 int값을 넘을수없습니다. 단, 결과가 int범위를 넘는것은 가능합니다.\n\n";
		hello++;
	}
	cout << "operand 1: "; cin >> number_a;
	opr.pushThis_2a(number_a);
	cout << "operand 2: "; cin >> number_b;
	opr.pushThis_2b(number_b);
	opr.addProcess();
	opr.popResult();
	cout << "\n\nretry ? \n0 to no,  1 to yes\n" ; cin >> re;
	if (re == 1)  goto initialize;
	return 0;
}
