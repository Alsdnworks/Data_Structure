#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

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
	Corona_World();
	Corona_World(const C_INFO& input);
	Corona_World(const vector<C_INFO>& input_list);
	~Corona_World();

	bool NewData(const C_INFO& input);
	bool DelData(string name);

	friend bool Arg_Rege(const C_INFO& a, const C_INFO& b);
	friend bool Arg_Pati(const C_INFO& a, const C_INFO& b);
	friend bool Arg_Dead(const C_INFO& a, const C_INFO& b);
	friend bool Arg_Rate(const C_INFO& a, const C_INFO& b);
	void Menu(int num);
	void cmp_Menu(int num);
	int option();

private:
	vector<C_INFO>list;
	vector<C_INFO>index;
};



bool Corona_World::NewData(const C_INFO& input)
{
	list.push_back(input);
	return true;
}

bool Arg_Rege(const C_INFO& a, const C_INFO& b)
{
	return a.Rege < b.Rege;
}
bool Arg_Pati(const C_INFO& a, const C_INFO& b)
{
	return a.Pati < b.Pati;
}
bool Arg_Dead(const C_INFO& a, const C_INFO& b)
{
	return a.Dead < b.Dead;
}
bool Arg_Rate(const C_INFO& a, const C_INFO& b)
{
	return a.D_Rate < b.D_Rate;
}
/*
bool Corona_World::DelData(string name) {
		int Tcount = 0;
		string input_iterator_tag;
		cin >> input_iterator_tag;
		index.push_back(input_iterator_tag);

		for (index.begin(); index!=list.end(); index=index+5){
			if (strcmp(key,index)==0) {
				index=list.erase(index);
				Tcount++;
			}
		}
		cout << Tcount << "���� �����Ͱ� �����Ǿ����ϴ�." << endl;
	}
	*/

void Corona_World::Menu(int num)
{
	switch (num)
	{
	case 1:
		bool NewData();
		break;
	case 2:
		bool DelData();
		break;
	case 3:
		void menu2();
		break;
	default:
		break;
	}
}

void Corona_World::cmp_Menu(int num) {
	cout << "�Է°��� �������� �����͸� ����մϴ�\n"
		<< "1.������ ������ ���\n"
		<< "2.�ߺ����� ������ ���\n"
		<< "3.����� ������ ���\n"
		<< "4.����� ������ ���\n" << endl;
	switch (num)
	{
	case 1:
		sort(list.begin(), list.end(), Arg_Rege);
		break;
	case 2:
		sort(list.begin(), list.end(), Arg_Pati);
		break;
	case 3:
		sort(list.begin(), list.end(), Arg_Dead);
		break;
	case 4:
		sort(list.begin(), list.end(), Arg_Rate);
		break;
	default:
		break;
	}
}
