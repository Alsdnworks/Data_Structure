#include<iostream>
using namespace std;
//Integer only
class intClass{
    int storage[50];
};
//Float only
class floatClass{
    float stroage[50];
};

// 이게효과적인가? 기능이 같다면 데이터타입을 변수에 정의하는방법이?

          //2.타입이 여기서 정의되서
template<class genType>
class num{
public:
    //3. 여기로 자동적용된다.
    genType a;
};

int main(){
    //1. int를 받는 부분이다.
 num<int> int_class;
 num<float> float_class;

 int_class.a=10;
 float_class.a=20.2;

 cout<<int_class.a<<endl<<float_class.a<<endl;
}