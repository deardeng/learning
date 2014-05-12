#ifndef LIST_H
#define LIST_H 1
#include<cstddef>
class List{
	struct Node{
		T data;
		Node* next;
		Node(const T& d=T()):data(d),next(0){}//零初始化
	};
	Node* head;//头指针，用来保存头节点的地址
	int len;
public:
	List():head(NULL),len(0){}
	void push_front(const T& d);//前插
	List& push_back(const T& d);//尾插
	int size()const;
	Node*& getptr(int pos);//找链表中指向指定位置的指针
	void insert(const T& d,int pos);//在任意位置插入
	void travel()const;//遍历
	void clear();//清空这个链表
	~List();
	void erase(int pos);//有效位置为0~size()-1
	void remove(const T& d);
	int find(const T& d)const;
	void set(int pos,const T& d);
	bool empty()const{return head == 0;}
	const T& front()const{if(empty())throw"空";return head->data;}
	const T& back()const;
};
#endif