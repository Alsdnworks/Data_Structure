#include<stdlib.h>
#include<iostream>

class IntSLLNode {
public:
	IntSLLNode() {
		next = 0;
	}
	IntSLLNode(int el, IntSLLNode* ptr = 0) {
		info = el; next = ptr;
	}
	int info;
	IntSLLNode* next;
};

class IntSLList {
public: 
	IntSLList() {
		head = tail = 0;
	}
	~IntSLList();
	int isEmpty() {
		return head == 0;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromTail();
	int deleteFromHead();
	void deleteNode(int);
	bool isInList(int) const;
private:
	IntSLLNode * head, * tail;
};

IntSLList::~IntSLList() {
	for (IntSLLNode* p; !isEmpty();) {
		p = head->next;
		delete head;
		head = p;
	}
}
void IntSLList::addToHead(int el) {
	head = new IntSLLNode(el, head);
	//테일0인것, 하나의 노드로 되어있다는것,,아무것도 없다
	if (tail == 0)
		tail = head;
}
void IntSLList::addToTail(int el) {
	//리스트가 empty가 아니다? 내용이있다는것으로 
	if (tail != 0) {//
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else head = tail = new IntSLLNode(el);
}
int IntSLList::deleteFromHead() {
	int el = head->info;
	IntSLLNode *tmp = head;
	if (head==tail)
	head=tail=0;
	else head = head->next;
	delete tmp;
	return el;
}
int IntSLList::deleteFromTail() {
	if (head==tail) {
		delete head;
		head =tail=0;
	}
	else { 
		IntSLLNode *tmp;
		//테일 전의 노드까지 이동하고 테일삭제, 테일은 널포인터를 가르키게된다.
		//테일을 템프에 할당해준다.5주차 파트2 41분참조
		for (tmp=head; tmp->next != tail; tmp->next);
			delete tail;
			tail=tmp;
			tail->next=0;
		}
	return el;	
}
void IntSLList::deleteNode(int el){
	if (head!=0)
	if (head(head==tail&&el==head->info){
		delete head;
		head=tail=0;
	}
	else if (el==head->info){
		IntSLLNode *tmp =head;
		head=head->next;
		delete tmp;
	}
	else {
		IntSLLNode*pred,*tmp;
		//DontPanic    :D
		for(pred=head, tmp=head->next; 
		tmp!=0 && !tmp->info==el);
		//여기중요 밑줄 쫙쫙
		pred=pred->next, tmp=tmp->next);

		if (tmp!=0){
			pred->next = tmp->next;
			if(tmp==tail)
				tail=pred;
			delete tmp;
		}
	}
}
//기본기를 바로잡자: 이 함수내에선 어떤 변수도 바꿀수 없음을 의미한다. 함수가 클래스멤버일때만 사용가능
//const가 붙은 함수 내에서는 const가 붙은 다른 함수를 제외한 일반 함수를 호출할수없다
bool IntSLList::isInList(int el) const{
	IntSLLNode *tmp;
	for (tmp=head;tmp!=0&&!(tmp->info==el);tmp=tmp->next);
	return tmp !=0;
}
