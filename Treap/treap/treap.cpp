#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;

template<class T>
class Node {
public:
    Node() {
        left = right = NULL;
    }
    Node(const T& val, const double& pri, Node* l = NULL, Node* r = NULL) {
        value = val;
        priorty = pri;
        left = l;
        right = r;
    }
    ~Node() {};
    T value;
    double priorty;
    Node*left , * right;
    Node* root;
    bool setRoot(string val, double prior);
    bool insertNode(string value, double priorty, Node* refer);
    bool processData();
private:

   };


typedef struct context {
    string name;
    int num_of_confirmed;
    int num_of_death;
    double rate_of_death = ((double)num_of_death / num_of_confirmed) * 100;
}context;
vector<context>list;

template<class T>
bool Node<T>:: setRoot(string val, double prior) {
    Node *newNode =new Node;
    newNode->priorty = prior;
    newNode->value=val;
    newNode->left;
    newNode->right;
    root = newNode;
    return true;
}

template<class T>
bool Node<T>::insertNode(string value, double priorty, Node* refer) {
    if (0 < value.compare(refer->value)) {
        if (refer->right == NULL) {
            Node* newNode = new Node;
            refer->right = newNode;
            newNode->value = value;
            newNode->priorty = priorty;
            return true;
        }
        else insertNode(value, priorty, refer->right);
    }
    if (0 > value.compare(refer->value)) {
        if (refer->left == NULL) {
            Node* newNode = new Node;
            refer->left = newNode;
            newNode->value = value;
            newNode->priorty = priorty;
            return true;
        }
        else insertNode(value, priorty, refer->left);
    }
    if (0 == value.compare(refer->value)) {
        cout << "중복되는 value"<<value<<endl;
        return false;
    }
}

bool Arg_Data(const context& a, const context& b) {
    return a.rate_of_death > b.rate_of_death;
}

template<class T>
bool Node<T>::processData() {
    sort(list.begin(), list.end(), Arg_Data);
    setRoot(list[0].name, list[0].rate_of_death);
    cout << "다음데이터를 Treap처리합니다 " << "\n" << list[0].name << "\n" << list[0].num_of_confirmed << "\n" << list[0].num_of_death << "\n" << list[0].rate_of_death << "\n" << "\n" << endl;

    for (int i = 1; i < list.size(); i++) {
        insertNode(list[i].name, list[i].rate_of_death,root);
        cout <<"다음데이터를 Treap처리합니다 " << "\n" << list[i].name<<"\n" << list[i].num_of_confirmed<<"\n" << list[i].num_of_death<<"\n" << list[i].rate_of_death<<"\n" << "\n" << endl;
    }
    return true;
}
//bool InsertData() {
//    
//}

int main() {
    Node <string> nodedata;

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