#pragma once
#include <iostream>
using namespace std;
class 베이스클래스 {
public:
	베이스클래스() { }
	void 퍼블릭(const char* s = "unknown") {
		cout << "Function 퍼블릭() in 베이스클래스 called from " << s << endl;
		비공개();
	}
protected:
	void 보호된(const char* s = "unknown") {
		cout << "Function 보호된() in 베이스클래스 called from " << s << endl;
	}
private:
	void 비공개() {
		cout << "Function 비공개() in 베이스클래스\n";
	}
};

class 파생1 : public virtual 베이스클래스 {
	//가상으로 선언됨 부모는 선언만되어있고 객체는 생성이 안되어있는
public:
	void 퍼블릭(const char* s = "unknown") {
		cout << "Function 퍼블릭() in 파생1 called from " << s << endl;
		보호된("파생1");
		비공개("파생1");
	}
	void 비공개(const char* s = "unknown") {
		cout << "Function 비공개() in 파생1 called from " << s << endl;
	}
};
class 파생2 : public virtual 베이스클래스 {
public:
	void 퍼블릭(const char* s = "unknown") {
		cout << "Function 퍼블릭() in 파생2 called from " << s << endl;
		보호된("파생2");
		// 비공개(); // error: 베이스클래스::비공개() is not accessible
	}
};

class 파생2상속2 : public 파생1, public 파생2 {
public:
	void 퍼블릭(const char* s = "unknown") {
		cout << "Function 퍼블릭() in 파생2상속2 called from " << s << endl;
		보호된("파생2상속2");
		파생1::비공개("파생2상속2");
		베이스클래스::퍼블릭("파생2상속2");
	}
};
//inheritance.h
