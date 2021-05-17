#include <iostream>
#include <cstdlib>
#include<ctime>
#include <vector>
#include<stack>
using namespace std;

template<class T>
class WBcheck {
public:
	WBcheck() {};
	~WBcheck() {};
	void init();
	void findWhite_ctrl();
	void findWhite(int x, int y);
	bool result();

private:
	const bool w = true, b = false;
	const short pass = 2;

	int i = 0, j = 0, k = 0;

	int count[64];
	int block[8][8];
};


template<class T>
void WBcheck<T>::init() {
	srand((unsigned int)time(NULL));
	cout << "Created pattern is:" << endl;
	for (i = 0; i <= 7; i++) {
		for (j = 0; j <= 7; j++) {
			if (rand() % 2 == 0) block[i][j] = b;
			else block[i][j] = w;
			cout << (int)block[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T>
void WBcheck<T>::findWhite_ctrl() {
	for (i = 0; i <= 7; i++) {
		for (j = 0; j <= 7; j++) {
			count[k] = 0;
			findWhite(i, j);
			k++;
		}
	}
}

template<class T>
void WBcheck<T>::findWhite(int x, int y) {
	if (block[x][y] == w) {
		block[x][y] = pass;
		count[k]++;
		if (x + 1 != 8)findWhite(x + 1, y);
		if (y + 1 != 8)findWhite(x, y + 1);
		if (x - 1 != -1)findWhite(x - 1, y);
		if (y - 1 != -1)findWhite(x, y - 1);
	}
}

template<class T>
bool WBcheck<T>::result() {
	int k = 0, i = 0;
	int size = 0;
	stack <int> res;

	while (k <= 63) {
		if (count[k] > 0) {
			res.push(count[k]);
			size++;
		}
		k++;
	}
	
	cout << size << " white areas of ";
	while (i <= (size - 2)) {
		cout << res.top() << ", ";
		res.pop();
		i++;
	}
	cout <<"and "<< res.top() << " cells";
	res.pop();

	if (res.empty() == false) return 1;
}

int main(){
	WBcheck<void> opr;

	cout << "1 as Whitecells, 0 as Blackcells" << endl;
	opr.init();
	cout << endl;
	opr.findWhite_ctrl();
	cout << endl;
	opr.result();
	cout << endl;
	return 0;
}

//if (rand()%2==0)block[i][j]=b;
//else block[i][j] = w;
//x y배열을 사용한다 WBconvert(x,y)
//배열의 상하좌우를 탐색하여 white를 찾아 재귀한다
//출력은 5 white areas of 1 , 21 ,10 and 2 cells.의 규격으로