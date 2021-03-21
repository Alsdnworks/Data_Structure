/*oop의 특징 문법적 클래스가가기지는 가장 큰 특징은 
캡슐화라고할수있다. 객체는 클래스에서 파생되는 인스턴스로 객체에는
데이터가들어가있고 포함이 되엉있다->Encapsulation
필요한 인풋이있어야하는곳은 외부접근으을 허용하고
내부에서동자하는 부분에는 외부접근을 막을수있다.
클래스는 붕어빵틀: 붕어빵의 생김새를 명다면
오브젝트는 붕어빵 실제 클래스모형으로부터의 실물=
클래스인스턴스(변수)
하나의 클래스를 정의하기위한 멤버변수의 변수를 실물화
*/
#include <iostream>
using namespace std;

	 class C {
	 public:
	 //문자열저장되있을때 첫 주소값을
 C(char *s=" ", int i=0, double d=0.0) {
	 //s를 데이터멤1로
 strcpy(dataMember1,s);
 dataMember2 = i;
 dataMember3 = d;
 }
 //출력을위한...
 void memberFunction1() {
 cout << dataMember1 << ' ' << dataMember2 << ' '
 << dataMember3 << endl;
 }
 void memberFunction2(int i, char *s = "unknown") {
 dataMember2 = i;
 cout << i << " received from " << s << endl;
 }
	 protected:
 char dataMember1[20];
 int dataMember2;
 double dataMember3;
	 };

	 C object1("object1",100,2000), object2("object2"), object3;
	