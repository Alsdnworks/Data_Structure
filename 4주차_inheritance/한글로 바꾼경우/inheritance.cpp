
#include <iostream>
#include <stdio.h>

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
		cout << "정상작동\n";
	}
};

class 파생1 {
	//가상으로 선언됨 부모는 선언만되어있고 객체는 생성이 안되어있는
public:
	void 퍼블릭(const char* s = "unknown") {
		cout << "Function 퍼블릭() in 파생1 called from " << s << endl;
		보호된("파생1");
		비공개("파생1");
	}
	void 비공개(const char* s = "unknown") {
		cout << "오류작동" << s << endl;
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
int main() {
	베이스클래스 bc;
	파생1 d1l1;
	파생2 d2l1;
	파생2상속2 dl2;
	cout << "\n\n베이스클래스 퍼블릭에서 main 1을 넣었을때" << endl;
	bc.퍼블릭("main(1)");
	// bc.보호된(); // error: 베이스클래스::보호된() is not accessible
	// bc.비공개(); // error: 베이스클래스::비공개() is not accessible
	cout << "\n\n파생1 퍼블릭에서 main 2을 넣었을때" << endl;
	d1l1.퍼블릭("main(2)");
	// d1l1.보호된(); // error: 베이스클래스::보호된() is not accessible
	cout << "\n\n파생1 비공개에서 main 3을 넣었을때" << endl;
	d1l1.비공개("main(3)");
	cout << "\n\n파생2 퍼블릭에서 main 4을 넣었을때" << endl;
	d2l1.퍼블릭("main(4)");
	// d2l1.보호된(); // error: 베이스클래스::보호된() is not accessible
	// d2l1.비공개(); // error: 베이스클래스::비공개() is not accessible
	cout << "\n\n파생2상속2 퍼블릭에서 main 5을 넣었을때" << endl;
	dl2.퍼블릭("main(5)");
	// dl2.보호된(); // error: 베이스클래스::보호된() is not accessible
	cout << "\n\n파생2상속2 인자없이" << endl;

	dl2.비공개();
	return 0;
}