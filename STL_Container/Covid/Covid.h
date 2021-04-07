#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <iomanip>

using namespace std;

typedef struct C_Database{
	string Rege;
	int Pati;
	int Dead;
	double D_Rate;
}C_Database;

class Corona_World{
public:
	Corona_World() {};
	//Corona_World(const C_Database& input) {};
	//Corona_World(const vector<C_Database>& input_list) {}; //어디에 사용되야하는자료인가
	~Corona_World() {};
	bool NewData(const C_Database& input);
	friend bool Arg_Rege(const C_Database& a, const C_Database& b);
	friend bool Arg_Pati(const C_Database& a, const C_Database& b);
	friend bool Arg_Dead(const C_Database& a, const C_Database& b);
	friend bool Arg_Rate(const C_Database& a, const C_Database& b);
	void Print(const vector<C_Database>& list);
	bool DelData(string name);
	void Menu(int num);
	void cmp_Menu(int num2);

private:
	vector<C_Database>list;
};

bool Corona_World::NewData(const C_Database& input){
	list.push_back(input);
	cout << "등록성공!" << endl;
	return true;
}

bool Arg_Rege(const C_Database& a, const C_Database& b){
	return a.Rege > b.Rege;
}
bool Arg_Pati(const C_Database& a, const C_Database& b){
	return a.Pati > b.Pati;
}
bool Arg_Dead(const C_Database& a, const C_Database& b){
	return a.Dead > b.Dead;
}
bool Arg_Rate(const C_Database& a, const C_Database& b){
	return a.D_Rate > b.D_Rate;
}

bool Corona_World::DelData(string name) {
		int Tcount = 0;
		vector<C_Database>::iterator itr = list.begin();
		for (; itr != list.end(); ++itr) {
			if ((*itr).Rege == name) {//스택오버플로에서 찾은 자료로했는데 말이 너무어려워서 이해포기 왜 포인터형식인가?
				list.erase(itr);
				if (list.size() == 0) {//이터레이터가 0일때 런타임오류생겨서 해둔조치 
					list.resize(1);
				}
				itr = list.begin();
				Tcount++;
			}
		}
		if (Tcount == 0) {
			cout << "입력한 국가명이 데이터베이스에 없습니다. 확인후 다시 시도하십시오. .\n" << endl;
		}
		else cout << "성공적으로 삭제되었습니다." << endl;		
		return true;
		//1개의 값중 1개가 지워지면 이터레이터 오류발생 (4/7)해결
	}


void Corona_World::Menu(int num){
	C_Database data;
	string name;
	double m_Drate;
	switch (num){
	case 1:
		cout << "----------새로운 데이터 등록----------" << endl;
		cout << "국가명: "; cin >> data.Rege;
		cout << "환자수: "; cin >> data.Pati;
		cout << "사망자: "; cin >> data.Dead;
		m_Drate = (((float)data.Dead / (float)data.Pati))*100.0f;
		data.D_Rate=m_Drate;
		Corona_World::NewData(data);
		break;
	case 2:
		cout << "----------데이터를 삭제합니다.----------" << endl;

		printf("삭제할 국가데이터의 지역명을 입력하세요.\n");
		cin >> name;
		Corona_World::DelData(name);
		break;
	case 3:	
		int set2;
		cout  << "----------데이터를 출력합니다----------\n"
		<< "1.지역명 순으로 출력\n"
		<< "2.발병숫자 순으로 출력\n"
		<< "3.사망자 순으로 출력\n"
		<< "4.사망률 순으로 출력\n" << endl;
		cin >> set2;
		cmp_Menu(set2);
		break;
	case 4:
		exit(0);
	default: {
		break; }
	}
}

void Corona_World::cmp_Menu(int num2) {//더 깔끔하게 할수는 없을까? 키를 함수의 인자로 보내서 처리하려고했는데 오류생겨서 포기
	int i=0;
	cout.precision(3);
	cout.setf(ios::left);
	cout << "발생지역" << "   " << "총환자수" << "   " << "사망자수" << "   " << "사망률" <<"\n"<< endl;
	switch (num2){
	case 1:
		sort(list.begin(), list.end(), Arg_Rege);
		for (i =0; i < list.size(); i++) {
			cout<< setw(11) <<  list[i].Rege<< setw(11) << list[i].Pati<< setw(11) << list[i].Dead<< setw(11) << list[i].D_Rate<< "\n" << endl;
		}
		break;
	case 2:
		sort(list.begin(), list.end(), Arg_Pati);
		for (i = 0; i < list.size(); i++) {
			cout << setw(11) << list[i].Rege << setw(11) << list[i].Pati << setw(11) << list[i].Dead << setw(11) << list[i].D_Rate << "\n" << endl;
		}
		break;
	case 3:
		sort(list.begin(), list.end(), Arg_Dead);
		for (i = 0; i < list.size(); i++) {
			cout << setw(11) << list[i].Rege << setw(11) << list[i].Pati << setw(11) << list[i].Dead << setw(11) << list[i].D_Rate << "\n" << endl;
		}
		break;
	case 4:
		sort(list.begin(), list.end(), Arg_Rate);
		for (i = 0; i < list.size(); i++) {
			cout << setw(11) << list[i].Rege << setw(11) << list[i].Pati << setw(11) << list[i].Dead << setw(11) << list[i].D_Rate <<"\n"<< endl;
		}
		break;
	default:
		break;
	}
}
