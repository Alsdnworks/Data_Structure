#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
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
    Node* left, * right;
    Node* root;
    int searchInit = 0;
    bool setRoot(const T& val, double prior);
    bool insertNode(const T& value, double priorty, Node* refer);
    bool processData();
    void isRoot(Node* chkNode);
    void nodeify(string m_name, int m_num_of_confirmed, int m_num_of_death);
    void searchname(string s_name);
    void search(string s_name, Node* refer);
    void initData();
};

typedef struct context {
    string name;
    int num_of_confirmed;
    int num_of_death;
    double rate_of_death = ((double)num_of_death / num_of_confirmed) * 100;
} context;
vector<context> list;