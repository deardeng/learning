#include<iostream>
using namespace std;
typedef int T;
#include"01list.h"
void List::push_front(const T&d){
	insert(d,0);
}
List& List::push_back(const T& d){//尾插
	insert(d,size());
	return *this;
}
int List::size()const{
	return len;
}
List::Node*& List::getptr(int pos){//找链表中指向指定位置的指针
	if(pos<0||pos>size()) pos = 0;
	if(pos == 0)return head;
	Node* p = head;
	for(int i=1;i<pos;i++)
		p = p->next;
	return (*p).next;
	//1:return (*p).next;
	//2:p=p->next:return (*p).next;
	//3:p=p->next:p=p->next;return (*p).next;
}
void List::insert(const T& d,int pos){//在任意位置插入
	Node*& pn = getptr(pos);
	Node* p = new Node(d);
	p->next = pn;
	pn = p;
	len++;
}
void List::travel()const{//遍历
	Node* p = head;
	while(p!=NULL){
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
void List::clear(){//清空这个链表
	while(head != NULL){
		Node* p = head->next;
		//	cout << "delete" << head << endl;
		delete head;
		head = p;
	}
	len = 0;
}
List::~List(){
	//cout << this << "*********" << head << endl;
	clear();
}
void List::erase(int pos){//有效位置为0~size()-1
	if(pos<0||pos>=size())return;
	Node*& pn = getptr(pos);
	Node* p = pn;
	pn = pn->next;
	delete p;
	--len;
}
void List::remove(const T& d){
	int pos;
	while((pos = find(d))!=-1)
		erase(pos);
}
int List::find(const T& d)const{
	Node* p = head;
	int pos=0;
	while(p){
		if(p->data==d)return pos;
		p = p->next;++pos;
	}
	return -1;
}
void List::set(int pos,const T& d){
	if(pos<0||pos>=size())return;
	getptr(pos)->data = d;
}
const T& List::back()const{
	if(empty())throw"NULL";
	Node* p=head;
	while(p!=NULL&&p->next!=NULL){
		p=p->next;
	}
	return p->data;
}
