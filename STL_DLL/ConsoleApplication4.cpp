//문제조건 DLL을 사용하는 코로나발병국리스트만들기
//Template클래스 형태로 구현
//노드추가는 AddtoDLLSorted(const T& e1)//국가면 순서에 맞는 위치에 노드추거
//노드삭제는 국가이름이 key
//입려된 노드를 출력하는 함수가있어야함
#include <iostream>

using namespace std;

class corona_nation{
public:
    corona_nation(string name = "empty", int num_of_confirmed_p = 0, int num_of_death_p = 0);
    ~corona_nation() {};
    void print_info();

    string m_name;
    int m_num_of_confirmed_p;
    int m_num_of_death_p;
    double m_death_rate;
};

template<class T>
class DLLNode{
public:
    DLLNode(){
        next = prev = NULL;
    }
    DLLNode(const T& el, DLLNode* n = NULL, DLLNode* p = NULL) {
        info = el;
        next = n;
        prev = p;
    }
    ~DLLNode() {};
    T info; //데이터를 저장할 멤버변수
    DLLNode* next, * prev;
};

template<class T>
class DLL
{
public:
    DLL(){
        head = NULL; // null로 지정하지 않으면?
    }

    ~DLL(){
        for (DLLNode<T>* p=new DLLNode<T>; p != NULL; ){
            p = head->next;
            delete head;
            head = p;
        }
    }
    void AddtoDLLSorted(const T& el);  //구현할것
    void deleteDLLSorted(const string& name); // 구현할것
    void printtDLLSorted(); //구현할것

private:
    DLLNode<T>* head,*tail;
};

template<class T>
void DLL<T>::AddtoDLLSorted(const T& el){
    DLLNode<T>* newIn=new DLLNode<T>;
    if (head == NULL) {
        head = newIn;
        tail = newIn;
        newIn->info = el;
        newIn->next = NULL;
        newIn->prev = NULL;
    }
    if(head != NULL) {
        newIn->info = el;
        tail->next =newIn ;
        newIn->prev = tail;
        newIn->next = NULL;
        tail = newIn;
        }
    } //구현완료?

template<class T>
void DLL<T>::deleteDLLSorted(const string& name){
    bool sw=false;
    DLLNode<T>* pre, * aft,* key = new DLLNode<T>, * del = new DLLNode<T>, * tmphead = new DLLNode<T>;
    tmphead->next = head;
    head->prev = tmphead;
    head = tmphead;
    key->info.m_name = name;
    for (pre = head; pre!= NULL;) {
        if (pre->next->info.m_name == key->info.m_name) {
            del = pre->next; aft = del->next;
            if (aft != nullptr) {
             pre->next = aft; aft->prev = pre;
            }
            sw++;
        }
        pre=pre->next;
    }
    head=tmphead->next;
    if (sw == true) {
        cout << "제거완료되었습니다." << endl;
    }
    else cout << "국가명을 찾을 수 없습니다." << endl;
    delete key;
    delete tmphead;
    delete del;
}//구현완료?
template<class T>
void DLL<T>::printtDLLSorted(){
    DLLNode<T>* m_prev = new DLLNode<T>;
    DLLNode<T>* iter = head;
    DLLNode<T>* m_next= iter->next;
    DLLNode<T>* m_nextnext = m_next->next;
    DLLNode<T>* temp = new DLLNode<T>;
    while (m_nextnext->next != nullptr) {
            if (m_next->info.m_num_of_death_p < iter->info.m_num_of_death_p) {
                temp = m_next;
                iter->next= m_nextnext;
                m_nextnext->prev = iter;
                temp->next = iter;
                iter->prev = temp;
                m_prev->next = temp;
                temp->prev = m_prev;
            }
            m_prev = iter->prev;
            iter = iter->next;
            m_next = m_next->next;
            m_nextnext = m_nextnext->next;
    }
    iter=head;
    while( iter!=NULL) {
        iter->info.print_info();
        iter = iter->next;
    }
    //구현중
  
}

corona_nation::corona_nation(string name, int num_of_confirmed_p, int num_of_death_p){
    m_name = name;
    m_num_of_confirmed_p = num_of_confirmed_p;
    m_num_of_death_p = num_of_death_p;
    m_death_rate = ((double)m_num_of_death_p / m_num_of_confirmed_p) * 100;
}

void corona_nation::print_info(){
    cout.width(10);
    cout << m_name;
    cout.width(10);
    cout << m_num_of_confirmed_p;
    cout.width(10);
    cout << m_num_of_death_p;
    cout.width(10);
    cout << m_death_rate << endl;
}

int main(){
    DLL<corona_nation> DLLdata;
    cout.width(10);
    cout << "국가명";
    cout.width(10);
    cout << "확진자수";
    cout.width(10);
    cout << "사망자수";
    cout.width(10);
    cout << "치명률" << endl;
    DLLdata.AddtoDLLSorted(corona_nation("Spain", 140510, 13798));
    DLLdata.AddtoDLLSorted(corona_nation("Italy", 135586, 17127));
    DLLdata.AddtoDLLSorted(corona_nation("Germany", 107591, 2012));
    DLLdata.AddtoDLLSorted(corona_nation("China", 81802, 3333));
    DLLdata.AddtoDLLSorted(corona_nation("France", 78167, 10328));
    DLLdata.AddtoDLLSorted(corona_nation("Iran", 62589, 3872));
    DLLdata.AddtoDLLSorted(corona_nation("U.K", 55242, 6159));

    while (1) {
        DLLdata.printtDLLSorted();
        cout << "삭제하고 싶은 나라 이름을 입력하세요:" ;
        string temp;
        cin >> temp;
        DLLdata.deleteDLLSorted(temp);
    }
        DLLdata.printtDLLSorted();
}