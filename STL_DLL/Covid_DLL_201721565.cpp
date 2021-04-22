#include <iostream>
#include <string>

using namespace std;

class corona_nation {
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
class DLLNode {
public:
    DLLNode() {
        next = prev = NULL;
    }
    DLLNode(const T& el, DLLNode* n = NULL, DLLNode* p = NULL) {
        info = el;
        next = n;
        prev = p;
    }
    ~DLLNode() {};
    T info;
    DLLNode* next, * prev;
};

template<class T>
class DLL {
public:
    DLL() {
        head = NULL;
    }
    ~DLL() {
        for (DLLNode<T>* p = new DLLNode<T>; p != NULL; ) {
            p = head->next;
            delete head;
            head = p;
        }
    }
    void AddtoDLLSorted(const T& el);
    void deleteDLLSorted(const string& name);
    void printtDLLSorted(int option);
    string Nameformat(string& name);

private:
    DLLNode<T>* head, * tail;
};

template<class T>
void DLL<T>::AddtoDLLSorted(const T& el) {
    DLLNode<T>* newIn = new DLLNode<T>;
    if (head == NULL) {
        head = newIn;
        tail = newIn;
        newIn->info = el;
        newIn->next = NULL;
        newIn->prev = NULL;
    }
    if (head != NULL) {
        newIn->info = el;
        tail->next = newIn;
        newIn->prev = tail;
        newIn->next = NULL;
        tail = newIn;
    }
}

template<class T>
void DLL<T>::deleteDLLSorted(const string& name) {
    DLLNode<T>* left, * right, * key = new DLLNode<T>, * target = new DLLNode<T>, * tmphead = new DLLNode<T>;
    bool isDelete = false;
    tmphead->next = head;
    head->prev = tmphead;
    head = tmphead;
    key->info.m_name = name;
    for (left = head; left->next != NULL;) {
        if (left->next->info.m_name == key->info.m_name) {
            target = left->next; right = target->next;
            if (right != nullptr) {
                left->next = right; right->prev = left;
            }
            else if (right == nullptr) {
                left->next = NULL;
                isDelete++;
                break;
            }
            isDelete++;
        }
        left = left->next;
    }
    head = tmphead->next;
    if (isDelete == true) {
        cout << "제거완료되었습니다." << endl;
    }
    else cout << "국가명을 찾을 수 없습니다." << endl;
}

template<class T>
void DLL<T>::printtDLLSorted(int option) {
    DLLNode<T>* iter = NULL; DLLNode<T>* index = NULL;
    corona_nation temp;
    if (head == NULL) {
        return;
    }
    else {
        for (iter = head; iter->next != NULL; iter = iter->next) {
            for (index = iter->next; index != NULL; index = index->next) {
                switch (option) {
                case 1:
                    if (iter->info.m_name > index->info.m_name) {
                        temp = iter->info;
                        iter->info = index->info;
                        index->info = temp;
                    }
                    break;
                case 2:
                    if (iter->info.m_num_of_confirmed_p > index->info.m_num_of_confirmed_p) {
                        temp = iter->info;
                        iter->info = index->info;
                        index->info = temp;
                    }
                    break;
                case 3:
                    if (iter->info.m_num_of_death_p > index->info.m_num_of_death_p) {
                        temp = iter->info;
                        iter->info = index->info;
                        index->info = temp;
                    }
                    break;
                case 4:
                    if (iter->info.m_death_rate > index->info.m_death_rate) {
                        temp = iter->info;
                        iter->info = index->info;
                        index->info = temp;
                    }
                    break;
                default:
                    cout << "잘못된 입력입니다";
                    return;
                }
            }
        }
    }
    cout.width(10);
    cout << "국가명";
    cout.width(10);
    cout << "확진자수";
    cout.width(10);
    cout << "사망자수";
    cout.width(10);
    cout << "치명률" << endl;
    iter = head;
    while (iter != NULL) {
        iter->info.print_info();
        iter = iter->next;
    }
}

template<class T>
string DLL<T>::Nameformat(string& m_name) {
    m_name[0] = toupper(m_name[0]);
    for (int i = 1; i < m_name.size(); i++) {
        m_name[i] = tolower(m_name[i]);
        return m_name;
    }
}

corona_nation::corona_nation(string name, int num_of_confirmed_p, int num_of_death_p) {
    m_name = name;
    m_num_of_confirmed_p = num_of_confirmed_p;
    m_num_of_death_p = num_of_death_p;
    m_death_rate = ((double)m_num_of_death_p / m_num_of_confirmed_p) * 100;
}

void corona_nation::print_info() {
    cout.width(10);
    cout << m_name;
    cout.width(10);
    cout << m_num_of_confirmed_p;
    cout.width(10);
    cout << m_num_of_death_p;
    cout.width(10);
    cout << m_death_rate << endl;
}

int main() {
    DLL<corona_nation> DLLdata;
    string delInput, m_name;
    int m_num_of_confirmed, m_num_of_death, mainMenuSet, subMenuSet;
    cout << "데이터구조::더블링크드리스트(DLL)를 사용하는 코로나 발병리스트 \n\n";
    DLLdata.AddtoDLLSorted(corona_nation("Spain", 140510, 13798));
    DLLdata.AddtoDLLSorted(corona_nation("Italy", 135586, 17127));
    DLLdata.AddtoDLLSorted(corona_nation("Germany", 107591, 2012));
    DLLdata.AddtoDLLSorted(corona_nation("China", 81802, 3333));
    DLLdata.AddtoDLLSorted(corona_nation("France", 78167, 10328));
    DLLdata.AddtoDLLSorted(corona_nation("Iran", 62589, 3872));
    DLLdata.AddtoDLLSorted(corona_nation("U.K", 55242, 6159));
    while (true) {
        cout << "----------명령을 선택하십시오----------\n"
            << "1.새로운 국가데이터를 추가합니다\n" << "2.데이터를 출력합니다\n"
            << "3.기존 국가데이터를 삭제합니다\n" << "4.프로그램 종료\n" << endl;
        cin >> mainMenuSet;
        if ((mainMenuSet < 1) || (mainMenuSet > 4)) {
            printf("잘못 입력하였습니다.\n");
            cin.clear();//내용초기화
            cin.ignore(100, '\n');//무시할 명령어의수와 이그노어 종료키 
            continue;
        }
        switch (mainMenuSet) {
        case 1:
            cout << "국가명입력: "; cin >> m_name;
            DLLdata.Nameformat(m_name);
            cout << "\n확진자수입력: "; cin >> m_num_of_confirmed;
            cout << "\n사망자수입력: ";  cin >> m_num_of_death;
            DLLdata.AddtoDLLSorted(corona_nation(m_name, m_num_of_confirmed, m_num_of_death));
            break;
        case 2:
            cout << "1.국가명으로 정렬\n" << "2.감염자수로 정렬\n"
                << "3.사망자수로 정렬\n" << "4.사망률로 정렬\n";
            cin >> subMenuSet;
            if ((subMenuSet < 1) || (subMenuSet > 4)) {
                printf("잘못 입력하였습니다.\n");
                cin.clear();//내용초기화
                cin.ignore(100, '\n');//무시할 명령어의수와 이그노어 종료키 
                continue;
            }
            DLLdata.printtDLLSorted(subMenuSet);
            break;
        case 3:
            cout << "삭제하고 싶은 나라 이름을 입력하세요:"; cin >> delInput;
            DLLdata.Nameformat(delInput);
            DLLdata.deleteDLLSorted(delInput);
            break;
        case 4:
            exit(0);
        }
    }
}
//4/21 소트알고리즘완성
//4/22 국가명 대소문자 보정, 스위치 예외처리 추가