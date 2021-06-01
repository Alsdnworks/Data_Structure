#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class Node
{
public:
    Node()
    {
        left = right = NULL;
    }
    Node(const T& val, const double& pri, Node* l = NULL, Node* r = NULL)
    {
        value = val;
        priorty = pri;
        left = l;
        right = r;
    }
    ~Node() {};
    T value;
    double priorty;

    Node* left, * right;
    Node* root;
    int newnodechk;
    bool setRoot(const T& val, double prior);
    bool insertNode(const T& value, double priorty, Node* refer);
    bool processData();
};

typedef struct context
{
    string name;
    int num_of_confirmed;
    int num_of_death;
    double rate_of_death = ((double)num_of_death / num_of_confirmed) * 100;
} context;
vector<context> list;
//bool newData(string name, int num_of_confirmed, int num_of_death) {
//    list.push_back({ name, num_of_confirmed, num_of_death });
//}

template <class T>
bool Node<T>::setRoot(const T& val, double prior)
{
    Node* newNode = new Node;
    newNode->priorty = prior;
    newNode->value = val;
    newNode->left;
    newNode->right;
    root = newNode;
    return true;
}

template <class T>
bool Node<T>::insertNode(const T& value, double priorty, Node* refer) {



    if (0 > value.name.compare(refer->value.name)) {//리퍼값보다 abc가작가
        if (refer->left == NULL && priorty < refer->value.rate_of_death) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->priorty = priorty;
            refer->left = newNode;
        }
        else if (priorty > refer->value.rate_of_death) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->priorty = priorty;
            Node* temp = new Node;
            *temp = *refer;
            *refer = *newNode;
            refer->left = temp;
            if (refer->right == NULL &&/*오른쪽이 비어있고 노드보다 작은 알파벳이면 가지를 쳐주자*/0 < temp->value.name.compare(refer->value.name)) {
                refer->left=temp->left;
                refer->right = temp;
                
            }
        }
        else
            insertNode(value, priorty, refer->left);
    }


    if (0 < value.name.compare(refer->value.name)) {//리퍼값보다 abc가작가
        if (refer->right == NULL && priorty < refer->value.rate_of_death) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->priorty = priorty;
            refer->right = newNode;
        }
        else if (priorty > refer->value.rate_of_death) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->priorty = priorty;
            Node* temp = new Node;
            *temp = *refer;
            *refer = *newNode;
            refer->left = temp;
            if (refer->right == NULL &&/*오른쪽이 비어있고 노드보다 작은 알파벳이면 가지를 쳐주자*/0 < temp->value.name.compare(refer->value.name)) {
                refer->left = temp->left;
                refer->right = temp;
            }
        }
        else
            insertNode(value, priorty, refer->right);
    }




    if (0 == value.name.compare(refer->value.name)) {
        cout << "중복되는 value" << value.name << endl;
        return false;
    }
}

bool Arg_Data(const context& a, const context& b)
{
    return a.rate_of_death > b.rate_of_death;
}

template <class T>
bool Node<T>::processData()
{
    setRoot(list[0], list[0].rate_of_death);
    cout << "다음데이터를 Treap처리합니다 "
        << "\n"
        << list[0].name << "\n"
        << list[0].num_of_confirmed << "\n"
        << list[0].num_of_death << "\n"
        << list[0].rate_of_death << "\n"
        << "\n"
        << endl;

    for (int i = 1; i < list.size(); i++)
    {
        insertNode(list[i], list[i].rate_of_death, root);
        cout << "다음데이터를 Treap처리합니다 "
            << "\n"
            << list[i].name << "\n"
            << list[i].num_of_confirmed << "\n"
            << list[i].num_of_death << "\n"
            << list[i].rate_of_death << "\n"
            << "\n"
            << endl;
    }
    return true;
}
//bool InsertData() {
//
//}

int main()
{
    Node<context> nodedata;

    list.push_back({ "Ftest", 100, 75 });
    list.push_back({ "Atest", 100, 55 });
    list.push_back({ "Dtest", 100, 60 });
    list.push_back({ "Ctest", 100, 70 });
    list.push_back({ "Htest", 100, 14 });
    list.push_back({ "Jtest", 100, 45 });
    list.push_back({ "Itest", 100, 65 });
    nodedata.processData();

    return 0;
}
//may 31 1400 first commit
//may 31 2200 템플릿, 틀잡기완료
//June 1  0100 입출력구조, 구조체 입력완료
//June 1  0400 데이터삽입구현, 테스트용 자동입력코드 제거(리팩토링)
//June 1  0700 삭제구현완료
//June 1  0900 relese