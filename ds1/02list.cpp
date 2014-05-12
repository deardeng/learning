#include<iostream>
using namespace std;
typedef int T;
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
	void push_front(const T& d){//前插
		insert(d,0);
	}
	List& push_back(const T& d){//尾插
		insert(d,size());
		return *this;
	}
	int size()const{
		return len;
	}
	Node*& getptr(int pos){//找链表中指向指定位置的指针
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
	void insert(const T& d,int pos){//在任意位置插入
		Node*& pn = getptr(pos);
		Node* p = new Node(d);
		p->next = pn;
		pn = p;
		len++;
	}
	void travel()const{//遍历
		Node* p = head;
		while(p!=NULL){
			cout << p->data << ' ';
			p = p->next;
		}
		cout << endl;
	}
	void clear(){//清空这个链表
		while(head != NULL){
			Node* p = head->next;
		//	cout << "delete" << head << endl;
			delete head;
			head = p;
		}
		len = 0;
	}
	~List(){
		//cout << this << "*********" << head << endl;
		clear();
	}
	void erase(int pos){//有效位置为0~size()-1
		if(pos<0||pos>=size())return;
		Node*& pn = getptr(pos);
		Node* p = pn;
		pn = pn->next;
		delete p;
		--len;
	}
	void remove(const T& d){
		int pos;
		while((pos = find(d))!=-1)
			erase(pos);
	}
	int find(const T& d)const{
		Node* p = head;
		int pos=0;
		while(p){
			if(p->data==d)return pos;
			p = p->next;++pos;
		}
		return -1;
	}
	void set(int pos,const T& d){
		if(pos<0||pos>=size())return;
		getptr(pos)->data = d;
	}
	bool empty()const{return head==NULL;}
	T front()const{if(empty())throw"空";return head->data;}
	T back()const{
		Node* p=head;
		while(p!=NULL&&p->next!=NULL){
			p=p->next;
		}
		return p->data;
	}
			
};
int main()
{
	List l;
	l.push_front(5);//5
	l.push_front(8);//8 5
	l.push_front(20);//20 8 5
	l.insert(9,2);//20 8 9 5
	l.insert(6,100);//6 20 8 9 5
	l.insert(7,-10);//7 6 20 8 9 5
	l.insert(1,2);//7 6 1 20 8 9 5
	l.push_back(10).push_back(15).travel();
	l.erase(0);//x7: 6 1 20 8 9 10 15
	l.erase(l.size()-1);//x15: 6 1 20 8 9 10
	l.erase(2);//x20: 6 1 8 9 10
	l.travel();
	l.push_back(6);//6 1 8 9 10 6
	l.insert(6,3);//6 1 8 6 9 5 10 6
	l.travel();
	l.remove(6);//1 8 9 5 10
	l.travel();
	l.set(0,666);
	l.set(4,789);
	l.set(l.find(9),123);
	l.set(1,777);
	l.travel();
	cout << l.front() << "..." << l.back() <<',' << l.size() << "个" <<  endl;
	while(!l.empty())l.erase(0);
	cout <<"size:" << l.size() << endl;
	return 0;
}
