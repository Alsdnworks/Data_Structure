#pragma once
#include <stdio.h>
using namespace std;
class BaseClass {
public:
	BaseClass() { }
	void f(const char* s = "unknown") {
		cout << "Function f() in BaseClass called from " << s << endl;
		h();
	}
protected:
	void g(const char* s = "unknown") {
		cout << "Function g() in BaseClass called from " << s << endl;
	}
private:
	void h() {
		cout << "Function h() in BaseClass\n";
	}
};

class Derived1Level1 : public virtual BaseClass {
public:
	void f(const char* s = "unknown") {
		cout << "Function f() in Derived1Level1 called from " << s << endl;
		g("Derived1Level1");
		h("Derived1Level1");
	}
	void h(const char* s = "unknown") {
		cout << "Function h() in Derived1Level1 called from " << s << endl;
	}
};
class Derived2Level1 : public virtual BaseClass {
public:
	void f(const char* s = "unknown") {
		cout << "Function f() in Derived2Level1 called from " << s << endl;
		g("Derived2Level1");
		// h(); // error: BaseClass::h() is not accessible
	}
};

class DerivedLevel2 : public Derived1Level1, public Derived2Level1 {
public:
	void f(const char* s = "unknown") {
		cout << "Function f() in DerivedLevel2 called from " << s << endl;
		g("DerivedLevel2");
		Derived1Level1::h("DerivedLevel2");
		BaseClass::f("DerivedLevel2");
	}
};