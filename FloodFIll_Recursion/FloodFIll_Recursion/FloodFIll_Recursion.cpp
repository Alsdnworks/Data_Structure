// FloodFIll_Recursion.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class WBcheck {
public:
	WBcheck() {};
	~WBcheck() {};
	void init();
	void display();
	void findWhite(int x, int y);
	void result();

private:
	const bool w=true, b=false; 
	int i=0, j=0, k=0;
	int count[64];
	int block[9][9];
	const short pass=2;
};


template<class T>
void WBcheck<T>::init() {
	for (i = 0; i <= 7; i++) {
		for (j = 0; j <= 7; j++) {
			if (rand() % 2 == 0) block[i][j] = b;
			else block[i][j] = w;
		}
	}
	display();
}
//최종본에서는 init와 display를 합칠것
template<class T>
void WBcheck<T>::display() {
	for (i = 0; i <= 7; i++) {
		for (j = 0; j <= 7; j++) {
			cout << (int)block[i][j]<<" ";
		}
		cout << endl;
	}
	
	for (i = 0; i <= 7; i++) {
		for (j = 0; j <= 7; j++) {	
			count[k]=0;
			findWhite(i,j);
			k++;
		}
	}
	
}

template<class T>
void WBcheck<T>::findWhite(int x, int y){
	if (block[x][y]==w){
		block[x][y]=pass;
		count[k]++;
		if (x+1!=8)findWhite(x+1,y);	
		if (y+1!=8)findWhite(x,y+1);
		if (x-1!=-1)findWhite(x-1,y);
		if (y-1!=-1)findWhite(x,y-1);
	}
}

template<class T>
void WBcheck<T>::result(){
	int k=0;
	while(k<=64){
		if (count[k]>0){
			cout << count[k]<<endl;
		}
		k++;
	}
	
}

int main()
{
	WBcheck<void> opr;

	opr.init();
	opr.result();
    std::cout << "Hello World!\n";
	return 0;
}

//if (rand()%2==0)block[i][j]=b;
//else block[i][j] = w;
//x y배열을 사용한다 WBconvert(x,y)
//배열의 상하좌우를 탐색하여 white를 찾아 재귀한다
//출력은 5 white areas of 1 , 21 ,10 and 2 cells.의 규격으로