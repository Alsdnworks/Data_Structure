#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>

using namespace std;

class Corona_World
{
	int i = 0;
	void NewData();
	void DelData();
	void Arg_Rege();
	void Arg_Pati();
	void Arg_Dead();
	void Arg_Rate();
	bool Comp();
	const char* Rege;
	const char* Cont;
	int Pati;
	int Dead;
	double D_Rate;

public:
	Corona_World(const char* Rege="",const char* Cont="", int Pati=0, int Dead=0, double D_Rate=0.0){}

	vector<Corona_World>NewData(vector<Corona_World>& list) {
		cin >> list[list.size() + 1].Rege;
		cin >> list[list.size() + 1].Cont;
		cin >> list[list.size() + 1].Pati;
		cin >> list[list.size() + 1].Dead;
		cin >> list[list.size() + 1].D_Rate;
		//메뉴로돌아간다
	}

	vector<Corona_World> DelData(vector<Corona_World>& list) {
		char* key;
		int Tcount = 0;
		cin >> key;
		for (i = 0; i < list.size(); i++) {
			if (key == list[i].Rege) {
				list.erase(list.begin() + i);
				Tcount++;
			}
		}
		cout << Tcount << "개의 데이터가 삭제되었습니다." << endl;
	}
	vector<Corona_World> Arg_Rege(vector<Corona_World> list) {
		vector<char>tmp;
		vector<Corona_World>::iterator idx;
		for (i = 0; i < list.size(); i++)//////////여기부터 막힘 벡터내 변수를 정렬하는 문제
		{
			sortlist[i].Rege
		}

	}
	vector<Corona_World> Arg_Pati(vector<Corona_World> list) {

	}
	vector<Corona_World> Arg_Dead(vector<Corona_World> list) {

	}
	vector<Corona_World> Arg_Rate(vector<Corona_World> list) {

	}
	bool i_operater(int& a, int& b)
	{
		if (a > b)
			return true;
		else
			return false;
	}
	bool d_operater(double& a, double& b)
	{
		if (a > b)
			return true;
		else
			return false;
	}
	bool c_operater(char& a, char& b)
	{
		if (a > b)
			return true;
		else
			return false;
	}



};

int main()
{
	int menu = 0;
	vector<Corona_World> list;
	cout << "데이터구조 4주차 STL -코로나 발병리스트-\n"
		<< "1.새로운 국가데이터를 추가합니다\n"
		<< "2.기존 국가데이터를 삭제합니다\n"
		<< "3.데이터를 출력합니다" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		void NewData();
		main();
	case 2:
		void DelData();
		break;
	case 3:
		menu2();
		break;
	default:
	}
}

void menu2() {
	int menu;
	cout << "입력값을 기준으로 데이터를 출력합니다\n"
		<< "1.지역명 순으로 출력\n"
		<< "2.발병숫자 순으로 출력\n"
		<< "3.사망자 순으로 출력\n"
		<< "4.사망률 순으로 출력\n" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		vector<Corona_World>Arg_Rege();
		main();
	case 2:
		vector<Corona_World>Arg_Pati();
		break;
	case 3:
		vector<Corona_World>Arg_Dead();
		main();
	case 4:
		vector<Corona_World>Arg_Rate();
		break;
	default:
		break;
	}
}

/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
														// Function Object
														//double operator() (double x){return 2*x;}
														//더블형태의 리턴을 가지는 연산자,피연산자 double x
vector<int> v1(0,1);								//   사이즈0-현재 몇개의데이터가있는가, 캐퍼시티1 -현재 메모리 몇개공간을 차지하는가
													//벡터의 인티져라고 볼수있다. 추가 데이터가있을때 사이즈와 캐퍼시티는자동으로 늘어난다.
vector<int> v2(3, 7);								// v2=(7 7 7 )
vector<int>::iterator i1= v1.begin()+1;        //벡터 i1은 v1의 시작점에서 +1이된 위치를 말한다.
											   //벡터는 배열식,함수의 접근을 허용한다 v5[1]=v5.at(3)=9    v5=(0 9 0 9 0)
v2.reserve(6);									 //캐퍼시티를 6으로늘려준다
v2.resize(5);									// 캐퍼시티를 유지한채 사이즈를 조정,
												//엘리먼트보다 많으면 남는공간을 0으로, 적으면 모자란만클 뒤부터 제거
vector<int> v4;
for (int i = 1; i <= 5; i++) {
	v1.push_back(i);
}

for (vector::iterator i = v4.begin(); i != v4.end(); i++)
cout << *i << endl;

int main();
vector.v1.clear();                             //사이즈초기화=값초기화, 캐퍼시티는 유지됨
for (int i = 0; i <= 5; i++)
{
	vector.v1.push_back(i);						//i포문이있는경우가정할때 순차적으로 밀어넣는다 v1=(1 2 3 4 5)
}


//과제: Vector를 활용한 국가별 코로나 감염정도 DB만들기
*/