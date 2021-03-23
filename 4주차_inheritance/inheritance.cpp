#include <iostream>
#include "inheritance.h"

using namespace std;



int main() {
	BaseClass bc;
	Derived1Level1 d1l1;
	Derived2Level1 d2l1;
	DerivedLevel2 dl2;
	bc.f("main(1)");
	// bc.g(); // error: BaseClass::g() is not accessible
	// bc.h(); // error: BaseClass::h() is not accessible
	d1l1.f("main(2)");
	// d1l1.g(); // error: BaseClass::g() is not accessible
	d1l1.h("main(3)");
	d2l1.f("main(4)");
	// d2l1.g(); // error: BaseClass::g() is not accessible
	// d2l1.h(); // error: BaseClass::h() is not accessible
	dl2.f("main(5)");
	// dl2.g(); // error: BaseClass::g() is not accessible
	dl2.h();
	return 0;
}