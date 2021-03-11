/*들어가기전에: 함수의재정의(function_overloading)
int add(int a, int b)
{}
int add(int a,int b,double c,)
{}
와 같이 값의 수나 형식이 다를때 적용시킬 차함수를 만들수있다.*/

//생성자와 소멸자의 정의//
/*
#include <iostream>
using namespace std;
class test{
public:
    void set_value(int input)
    {
        m_v1=input;
    }

    }
private:
    int m_v1;
};
//보통은 이게 기본인데 생성자를 사용해
// class test에 적용하면*/


#include <iostream>
using namespace std;
class test{
    public:
        test()/*생성자*/
         {
              m_v1=10;
         }
        test(int input)
        {
            m_v1=input;
        }

        void printvalue()
        {
        cout<<m_v1<<endl;
        }
    
    private:
        int m_v1;   
            };

int main(){
    test ct;
    ct.printvalue();/*생성자외부정의: 바로 10출력*/
    test ct2(20);
    ct.printvalue();/*생성자 내부정의:const가 있어서 20출력*/
    return 0;
}
