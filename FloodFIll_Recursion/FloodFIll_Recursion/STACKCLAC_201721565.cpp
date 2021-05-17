#include <iostream>
#include <stack>
using namespace std;

template<class T>
class StackCalc {
public:
	StackCalc() {};
	~StackCalc() {};
	void addProcess();
	void aPushReverse(__int64 num);
	void bPushReverse(__int64 num);
	void printPop();

private:
	stack<int>m_a;
	stack<int>m_b;
	stack<int>a;
	stack<int>b;
	stack<int>result;
};


template<class T>
void StackCalc<T>::bPushReverse(__int64 num) {
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
void StackCalc<T>::aPushReverse(__int64 num) {
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
void StackCalc<T>::addProcess() {
	int carry=0;
	int addElemet;

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
			if (a.empty() == false || b.empty() == false) {
				addElemet = addElemet - 10;
			}
		}
		result.push(addElemet);
	}
}


template<class T>
void StackCalc<T>::printPop() {
	int digit;

	cout << "Result: ";
	if (result.empty() == true)
		cout << "0";
	while (result.empty() == false) {
		digit = result.top();
		cout << digit;
		result.pop();
	}
}


int main() {
	bool hello = 0;
initialize:
	StackCalc<int> opr;
	__int64 number_a, number_b;
	bool re = 0;
	if (hello == 0) {
		cout << "-Stack을 이용한 정수간 덧셈 계산기 201721565손민우-\n";
		cout << "각 오퍼랜드값은 __int64값을 넘을 수 없습니다. 단, 결과가 범위를 넘는것은 가능합니다.\n";
		cout << "carry가 없는 차를 계산 할 수 있습니다.\n\n";
		hello=true;
	}
	cout << "operand 1: "; cin >> number_a;
	opr.aPushReverse(number_a);
	cout << "operand 2: "; cin >> number_b;
	opr.bPushReverse(number_b);
	opr.addProcess();
	opr.printPop();
	cout << "\n\nRetry ? \n 1 to yes\n" ; cin >> re;
	if (re == 1)  goto initialize;
	return 0;
}
