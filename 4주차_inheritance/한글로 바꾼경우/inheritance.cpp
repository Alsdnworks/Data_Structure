
#include "inheritance.h"
#include <iostream>
#include <stdio.h>

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