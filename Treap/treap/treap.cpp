#include"data.cpp"

template <class T>
bool Node<T>::setRoot(const T& val, double prior) {
    Node* newNode = new Node;
    newNode->priorty = prior;
    newNode->value = val;
    newNode->left;
    newNode->right;
    root = newNode;
    return true;
}

template <class T>
void Node<T>::isRoot(Node* chkNode) {
    if (chkNode->value.rate_of_death > root->value.rate_of_death)
        root = chkNode;
}

template <class T>
void Node<T>::nodeify(string m_name, int m_num_of_confirmed, int m_num_of_death) {
    list.push_back({ m_name, m_num_of_confirmed, m_num_of_death });
    insertNode(list.back(), list.back().rate_of_death, root);
}
template <class T>
void Node<T>::searchname(string s_name) {
    search(s_name, root);
}
template <class T>
void Node<T>::search(string s_name, Node* refer) {
    if (s_name < (refer->value.name)) {
        if (refer->left == NULL)
            cout << "찾을수없습니다.";
        else search(s_name, refer->left);
    }
    if (s_name > (refer->value.name)) {
        if (refer->right == NULL)
            cout << "찾을수없습니다.";
        else search(s_name, refer->right);
    }
    if (s_name == refer->value.name)
        //찾는값이 노드랑 일치하지 않음 보다 큰 알파벳 오른쪽 탐색, 작은 좌측 탐색,찾는값이면 출력,리프노드인데 찾는값이 없다? 미확인표시
        if (s_name == refer->value.name) {
            cout << (string)refer->value.name << "에 대한 자료입니다" << endl
                << "확진자" << (int)refer->value.num_of_confirmed << "명, 사망자"
                << (int)refer->value.num_of_death << "명, 치명률"
                << (double)refer->value.rate_of_death << "%" << endl;
        }
}

template <class T>
bool Node<T>::insertNode(const T& value, double priorty, Node* refer) {
    if (0 > value.name.compare(refer->value.name)) { //리퍼값보다 abc가작가
        if (refer->left == NULL && priorty < refer->value.rate_of_death) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->priorty = priorty;
            refer->left = newNode;
            isRoot(newNode);
            return true;
        }
        else if (priorty > refer->value.rate_of_death) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->priorty = priorty;
            Node* temp = new Node;
            *temp = *refer;
            *refer = *newNode;
            refer->left = temp;
            if (refer->right == NULL && 0 < temp->value.name.compare(refer->value.name)) {
                /*오른쪽이 비어있고 노드보다 작은 알파벳이면 가지를 쳐주자*/
                refer->left = temp->left;
                refer->right = temp;
            }
            isRoot(newNode);
            return true;
        }
        else insertNode(value, priorty, refer->left);
    }
    if (0 < value.name.compare(refer->value.name)) { //리퍼값보다 abc가크기
        if (refer->right == NULL && priorty < refer->value.rate_of_death) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->priorty = priorty;
            refer->right = newNode;
            isRoot(newNode);
            return true;
        }
        else if (priorty > refer->value.rate_of_death) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->priorty = priorty;
            Node* temp = new Node;
            *temp = *refer;
            *refer = *newNode;
            refer->left = temp;
            if (refer->right == NULL && 0 < temp->value.name.compare(refer->value.name)) {
                refer->left = temp->left;
                refer->right = temp;
            }
            isRoot(newNode);
            return true;
        }
        else insertNode(value, priorty, refer->right);
    }
    if (0 == value.name.compare(refer->value.name)) {
        cout << "중복되는 value" << value.name << endl;
        return false;
    }
    return false;
}
template <class T>
bool Node<T>::processData() {
    setRoot(list[0], list[0].rate_of_death);
    cout << "다음데이터를 Treap처리합니다 "
        << "\n" << list[0].name << "\n" << list[0].num_of_confirmed << "\n"
        << list[0].num_of_death << "\n" << list[0].rate_of_death << "\n"
        << "\n" << endl;

    for (int i = 1; i < list.size(); i++) {
        insertNode(list[i], list[i].rate_of_death, root);
        cout << "다음데이터를 Treap처리합니다 "
            << "\n" << list[i].name << "\n" << list[i].num_of_confirmed << "\n"
            << list[i].num_of_death << "\n" << list[i].rate_of_death << "\n" << "\n" << endl;
    }
    return true;
}
int main() {
    string a;
    int b;
    int c;
    Node<context> nodedata;
    nodedata.InitData();
    list.push_back({ "Dtest", 100, 60 });
    list.push_back({ "Htest", 100, 14 });
    list.push_back({ "Ftest", 100, 75 });
    list.push_back({ "Atest", 100, 55 });
    list.push_back({ "Ctest", 100, 70 });
    list.push_back({ "Jtest", 100, 45 });
    list.push_back({ "Itest", 100, 65 });
    nodedata.processData();

    cin >> a; /*
    cin >> b;
    cin >> c;
    nodedata.nodeify(a, b, c);
    nodedata.searchname(a);*/

    return 0;
}
//may 31 1400 first commit
//may 31 2200 템플릿, 틀잡기완료
//June 1  0100 입출력구조, 구조체 입력완료
//June 1  2200 데이터삽입구현
//June 1  2300 탐색구현완료
//June 1  2400 메인메뉴구성
//June 2  ???? 삭제구현완료
//June 2  ???? 최종리팩토링,테스트용 자동입력코드 제거
//June 2  ???? relese