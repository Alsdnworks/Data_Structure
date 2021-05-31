#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;

typedef struct context {
    string name;
    int num_of_confirmed;
    int num_of_death;
    double rate_of_death = ((double)num_of_death / num_of_confirmed) * 100;
}context;
vector<context>list;

typedef struct Node {
    string value=NULL;
    double priorty=0;
    struct Node* left;
    struct Node* right;
}Node;
Node* root;


bool setRoot(string val, double prior) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->priorty = prior;
    newNode->value=val;
    newNode->left;
    newNode->right;
    root = newNode;
    return true;
}


bool insertNode(string value, double priorty, Node* refer) {
    if (0 > value.compare(refer->value)) {
        if (refer->right == NULL) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            refer->right = newNode;
            newNode->value = value;
            newNode->priorty = priorty;
            return true;
        }
        else insertNode(value, priorty, refer->right);
    }
    if (0 < value.compare(refer->value)) {
        if (refer->left == NULL) {
            Node* newNode = (Node*)malloc(sizeof(Node));
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
bool processData() {
    sort(list.begin(), list.end(), Arg_Data);
    setRoot(list[0].name, list[0].rate_of_death);
    for (int i = 1; i < list.size(); i++) {
        insertNode(list[i].name, list[i].rate_of_death,root);
        cout <<"다음데이터 처리"<< list[i].name<<"\n" << list[i].num_of_confirmed<<"\n" << list[i].num_of_death<<"\n" << list[i].rate_of_death<<"\n" << "\n" << endl;
    }
    return true;
}
bool InsertData() {
    
}
int main() {
    // InitRoot();
    list.push_back({ "Algeria", 126860, 3418 });
    list.push_back({ "Romania", 1075773, 29977 });
    list.push_back({ "Russia", 5001505, 118482 });
    list.push_back({ "San_Marino", 5089, 90 });
    list.push_back({ "Serbia", 709939, 6777 });
    list.push_back({ "Slovakia", 772833, 12296 });
    list.push_back({ "Slovenia", 251773, 4675 });
    list.push_back({ "Spain", 3647520, 79711 });
    list.push_back({ "Sweden", 1063183, 14396 });
    processData();
    
    return 0;
}