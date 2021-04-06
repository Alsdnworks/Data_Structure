#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <iomanip>

using namespace std;

typedef struct C_INFO
{
	string Rege;
	int Pati;
	int Dead;
	double D_Rate;
}C_INFO;

class Corona_World

{
public:
	Corona_World() {};
	Corona_World(const C_INFO& input) {};
	Corona_World(const vector<C_INFO>& input_list) {};
	~Corona_World() {};

	bool NewData(const C_INFO& input);

	friend bool Arg_Rege(const C_INFO& a, const C_INFO& b);
	friend bool Arg_Pati(const C_INFO& a, const C_INFO& b);
	friend bool Arg_Dead(const C_INFO& a, const C_INFO& b);
	friend bool Arg_Rate(const C_INFO& a, const C_INFO& b);
	void Print(const vector<C_INFO>& list);
	bool DelData(string name);
	void Menu(int num);
	void cmp_Menu(int num2);

private:
	vector<C_INFO>list;
	vector<C_INFO>index;
};



bool Corona_World::NewData(const C_INFO& input){
	list.push_back(input);
	return true;
}

bool Arg_Rege(const C_INFO& a, const C_INFO& b){
	return a.Rege < b.Rege;
}
bool Arg_Pati(const C_INFO& a, const C_INFO& b){
	return a.Pati < b.Pati;
}
bool Arg_Dead(const C_INFO& a, const C_INFO& b){
	return a.Dead < b.Dead;
}
bool Arg_Rate(const C_INFO& a, const C_INFO& b){
	return a.D_Rate < b.D_Rate;
}

bool Corona_World::DelData(string name) {
		int Tcount = 0;

		vector<C_INFO>::iterator itr = list.begin();
		for (; itr != list.end(); ++itr) {
			if ((*itr).Rege == name) {
				list.erase(itr);
				if (list.size() == 0) {
					list.resize(1);
				}
				itr = list.begin();
				Tcount++;
			}
		}
		cout << Tcount << "개의 데이터가 삭제되었습니다.\n" << endl;
		return true;
		//1개의 값중 1개가 지워지면 이터레이터 오류발생
	}


void Corona_World::Menu(int num){
	C_INFO data;
	string name;
	double m_Drate;
	switch (num){
	case 1:
		
		cout << "국가명: "; cin >> data.Rege;
		cout << "환자수: "; cin >> data.Pati;
		cout << "사망자: "; cin >> data.Dead;
		m_Drate = ((float)data.Dead / (float)data.Pati);
		data.D_Rate=m_Drate;
		Corona_World::NewData(data);
		break;
	case 2:
		printf("삭제할 국가데이터의 지역명을 입력하세요.\n\n");
		cin >> name;
		Corona_World::DelData(name);
		break;
	case 3:	
		int set2;
		cout  << "입력값을 기준으로 데이터를 출력합니다\n"
		<< "1.지역명 순으로 출력\n"
		<< "2.발병숫자 순으로 출력\n"
		<< "3.사망자 순으로 출력\n"
		<< "4.사망률 순으로 출력\n" << endl;
		cin >> set2;
		cmp_Menu(set2);
		break;
	default:
		break;
	}
}

void Corona_World::cmp_Menu(int num2) {
	int i=0;
	cout.precision(3);
	cout.setf(ios::left);
	cout << "발생지역" << "   " << "총환자수" << "   " << "사망자수" << "   " << "사망률" << endl;

	switch (num2){
	case 1:
		sort(list.begin(), list.end(), Arg_Rege);
		for (i =0; i < list.size(); i++) {
			cout<< setw(11) <<  list[i].Rege << setw(11) << list[i].Pati<< setw(11) << list[i].Dead<< setw(11) << list[i].D_Rate<< endl;
		}
		break;
	case 2:
		sort(list.begin(), list.end(), Arg_Pati);
		for (i = 0; i < list.size(); i++) {
			cout << setw(11) << list[i].Rege << setw(11) << list[i].Pati << setw(11) << list[i].Dead << setw(11) << list[i].D_Rate << endl;
		}
		break;
	case 3:
		sort(list.begin(), list.end(), Arg_Dead);
		for (i = 0; i < list.size(); i++) {
			cout << setw(11) << list[i].Rege << setw(11) << list[i].Pati << setw(11) << list[i].Dead << setw(11) << list[i].D_Rate << endl;
		}
		break;
	case 4:
		sort(list.begin(), list.end(), Arg_Rate);
		for (i = 0; i < list.size(); i++) {
			cout << setw(11) << list[i].Rege << setw(11) << list[i].Pati << setw(11) << list[i].Dead << setw(11) << list[i].D_Rate << endl;
		}
		break;
	default:
		break;
	}
}
