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
			cin >> set;
				if ((set < 1) || (set > 4)){
						printf("잘못 입력하였습니다.\n");
						cin.clear();//내용초기화
						cin.ignore(100,'\n');//무시할 명령어의수와 이그노어 종료키 
						continue;
					}
				else{
						cvd.Menu(set);
					}
}
return 0;
}