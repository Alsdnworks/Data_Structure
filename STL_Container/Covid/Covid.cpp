#include "Covid.h"
int main() {
		Corona_World cvd;
		cout << "\n데이터구조 4주차 STL -코로나 발병리스트-\n"<<endl;
		while (true) {
		cout << "----------명령을 선택하십시오----------\n"
			<< "1.새로운 국가데이터를 추가합니다\n"
			<< "2.기존 국가데이터를 삭제합니다\n"
			<< "3.데이터를 출력합니다\n" 
			<< "4.프로그램 종료\n" << endl;
		int set = 0;
		cin >> set;//디버그결과 이게 씹혀서 생긴 문제, 해결법은..?
		cvd.Menu(set);
	}//규격외 값이 들어올때 문제 발생
	return 0;
}