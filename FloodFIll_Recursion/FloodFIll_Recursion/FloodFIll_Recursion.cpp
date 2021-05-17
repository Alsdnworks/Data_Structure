#include <iostream>
#include <cstdlib>
#include<ctime>
#include <vector>
#include<stack>
using namespace std;

template<class T>
class FloodFill {
public:
	FloodFill() {};
	~FloodFill() {};
	void init();
	void WBconvert_ctrl();
	void WBconvert(int x, int y);
	void result();

private:
	const bool w = true, b = false;
	int x = 0, y = 0, context = 0;
	int count[64];
	int block[8][8];
};


template<class T>
void FloodFill<T>::init() {
	srand((unsigned int)time(NULL));//난수생성
	cout << "Created pattern is:" << endl;
	for (x = 0; x <= 7; x++) {
		for (y = 0; y <= 7; y++) {
			if (rand() % 2 == 0) block[x][y] = b;
			else block[x][y] = w;
			cout << (int)block[x][y] << " ";
		}
		cout << endl;
	}
}

template<class T>
void FloodFill<T>::WBconvert_ctrl() {
	for (x = 0; x <= 7; x++) {
		for (y = 0; y <= 7; y++) {
			count[context] = 0;
			WBconvert(x, y);
			context++;
		}
	}
}

template<class T>
void FloodFill<T>::WBconvert(int x, int y) {
	if (block[x][y] == w) {
		block[x][y] = b;
		count[context]++;
		if (x + 1 != 8)WBconvert(x + 1, y);               //Recursion
		if (y + 1 != 8)WBconvert(x, y + 1);
		if (x - 1 != -1)WBconvert(x - 1, y);
		if (y - 1 != -1)WBconvert(x, y - 1);
	}
}

template<class T>
void FloodFill<T>::result() {
	int i = 0, size = 0;
	context = 0;
	stack <int> reversedRes;
	stack <int> res;

	while (context <= 63) {
		if (count[context] > 0) {
			reversedRes.push(count[context]);
			size++;
		}
		context++;
	}
	while (!reversedRes.empty()) {
		res.push(reversedRes.top());
		reversedRes.pop();
	}
	cout << size << " white areas of ";
	while (i <= (size - 2)) {
		cout << res.top() << ", ";
		res.pop();
		i++;
		}
	cout << "and " << res.top() << " cells";
	res.pop();
}

int main() {
	FloodFill<void> opr;
	bool re = 0;
	cout << "-재귀함수를 사용하는 4방향 FloodFill 구현 201721565손민우-\n\n";
	cout << "1 as Whitecells, 0 as Blackcells" << endl;
	opr.init();
	opr.WBconvert_ctrl();
	opr.result();
	cout << endl;

	cout << "\n\nretry ?  0 to no,  1 to yes\n"; cin >> re;
	if (re == 1)  main();      //Recursion!
	return 0;
}

//if (rand()%2==0)block[x][y]=b;에서 	srand((unsigned int)time(NULL)); 난수생성
//x y배열을 사용한다 WBconvert(x,y), 디버그편의성을위해 2개 함수로 분리
//배열의 상하좌우를 탐색하여 white를 찾아 재귀한다. white는 black으로 변환
//외곽을 0으로 채우는것대신 배열을 벗어나지 않도록 제어문 사용
//출력은 5 white areas of 1 , 21 ,10 and 2 cells.의 규격으로