//함수가 끝날때 꼭 해줘야하는 일을 기입하는 공간
//동적할당에서 new로 가져간 메모리 값을 delete한다던가에 사용
#include <iostream>
using namespace std;
class test{
    public:
        test()/*생성자, 공간미지정시*/
         {/*동적할당*/
              score = new int[10];
         }

         test(int num)/*입력값이있다면?*/
         {
         score=new int[num];
         }

       ~test()/*소멸자*/
        {/*동적할당 해제*/
            delete[] score;
        }
    /*private클래스에 동적할당을 위한 포인터스코어변수*/
    private:
        int *score;
};

int main()
{
    /*내용생략*/
 return 0;
}
