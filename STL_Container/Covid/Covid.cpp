#include "Covid.h"
int main(){
	Corona_World start;
	int option=0;
	cin >> option;
	cout << "데이터구조 4주차 STL -코로나 발병리스트-\n"
		<< "1.새로운 국가데이터를 추가합니다\n"
		<< "2.기존 국가데이터를 삭제합니다\n"
		<< "3.데이터를 출력합니다" << endl;
	start.Menu(option);
	return 0;
}
