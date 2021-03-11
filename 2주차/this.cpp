#include <iostream>
using namespace std;

class test
{
public:
	int m_v1;
	void print_var()
	{
				//클래스 멤버함수로서 'this' 객체화된 자신(주소값)
				/*
				CTest t;
				CTest*pT=&t;
				pT->show
				이는==(*pT).show()와 같다. pT=null이면? 안되는거지
				*/
		cout << m_v1 << endl;
		cout << this << endl;

		cout << this ->m_v1<<endl;

	}

};

int main()
{
	test c1,c2,c3;
	c1.m_v1 = 10;
	c1.print_var();
	cout << &c1 << endl;

	c2.m_v1 = 20;
	c2.print_var();
	cout << &c2 << endl;

	return 0;
}
