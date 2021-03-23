#include<iostream>
using namespace std;

template<class genType>

void swap(genType& INPUTa, genType& INPUTb)
{
genType t=INPUTa;
INPUTa=INPUTb;
INPUTb=t;
};


int main()
{
int a=10;
int b=20;

double c=34.2;
double d=45.3;

swap(a,b);//오버로드된 함수의 호출이 모호
swap(c,d);
cout << a << " " <<b<< endl;
cout << c << " " <<d<< endl;
}