//4/17 교수님 가이드코드
#include <iostream>

using namespace std;

class corona_nation
{
public:
    corona_nation(string name = "empty", int num_of_confirmed_p =0 , int num_of_death_p =0 );
    void print_info();
    
    
    string m_name;
    int m_num_of_confirmed_p;
    int m_num_of_death_p;
    double m_death_rate;
};

template<class T>
class DLLNode
{
public:
    DLLNode()
    {
        next=prev=NULL;
    }
    DLLNode(const T& el, DLLNode *n=NULL , DLLNode *p=NULL) {
        info=el;
        next=n;
        prev=p;
    }
    
    T info;
    DLLNode *next,*prev;
};

template<class T>
class DLL
{
public:
    DLL()
    {
        head=NULL; // null로 지정하지 않으면?
    }
    
    ~DLL()
    {
        for (DLLNode<T> *p; p!=NULL ; )
        {
            p= head->next;
            delete head;
            head = p;
        }
    }
    
    void AddtoDLLSorted(const T& el);  //구현할것
    void deleteDLLSorted(const string& name); // 구현할것
    void printtDLLSorted(); //구현할것
    
private:
    DLLNode<T> *head;
};

template<class T>
void DLL<T>::AddtoDLLSorted(const T& el)
{
    //구현하세요
    
}

template<class T>
void DLL<T>::deleteDLLSorted(const string& name)
{
    //구현하세요
}

template<class T>
void DLL<T>::printtDLLSorted()
{
    //구현하세요
}


corona_nation::corona_nation(string name , int num_of_confirmed_p  , int num_of_death_p )
{
    m_name=name;
    m_num_of_confirmed_p=num_of_confirmed_p;
    m_num_of_death_p=num_of_death_p;
    m_death_rate = ((double)m_num_of_death_p / m_num_of_confirmed_p) * 100;
}

void corona_nation::print_info()
{
    cout.width(10);
    cout << m_name;
    cout.width(10);
    cout << m_num_of_confirmed_p;
    cout.width(10);
    cout << m_num_of_death_p;
    cout.width(10);
    cout << m_death_rate << endl;
}


int main()
{
    DLL<corona_nation> DLLdata;
  
    
    DLLdata.AddtoDLLSorted( corona_nation("USA", 387547, 12291) );
    DLLdata.AddtoDLLSorted( corona_nation("Spain", 140510, 13798) );
    DLLdata.AddtoDLLSorted( corona_nation("Italy", 135586, 17127) );
    DLLdata.AddtoDLLSorted( corona_nation("Germany", 107591, 2012) );
    DLLdata.AddtoDLLSorted( corona_nation("China", 81802, 3333) );
    DLLdata.AddtoDLLSorted( corona_nation("France", 78167, 10328) );
    DLLdata.AddtoDLLSorted( corona_nation("Iran", 62589, 3872) );
    DLLdata.AddtoDLLSorted( corona_nation("U.K", 55242, 6159) );
    
    DLLdata.printtDLLSorted();
    
    cout << "삭제하고 싶은 나라 이름을 입력하세요:" <<endl;
    
    string temp;
    
    cin >> temp;
    
    DLLdata.deleteDLLSorted(temp);
    
    DLLdata.printtDLLSorted();
}