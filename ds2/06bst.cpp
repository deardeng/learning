#include<iostream>
using namespace std;
typedef char T;
class bst{
	struct Node{
		T data;
		Node* L;
		Node* R;
		Node(const T& d):data(d),L(),R(){}
		Node(const T& d,Node* l,Node* r):data(d),L(l),R(r){}
	};
	typedef Node* tree;
	Node* rp;
	int n;
public:
	bst():rp(),n(){}
	void clear(){clear(rp);n=0;}
	~bst(){clear();}
	const tree& rt()const{
		return rp;
	}
	void insert(const T& d){insert(rp,new Node(d));++n;}
	tree& find(const T& d){return find(rp,d);}
	void travel()const{travel(rp);cout<<endl;}
	bool empty()const{return rp==NULL;}
	int size()const{return n;}
	void update(const T& olddate,const T& newdata){
		if(remove(olddate))insert(newdata);
	}
	bool remove(const T& d){
			tree& t = find(d);
			if(t==NULL)return false;
			Node* p = t;
			if(t->L!=NULL)insert(t->R,t->L);
			t = t->R;
			delete p;
			--n;
			return true;
	}
	const T& root()const{if(!rp)throw "空";return rp->data;}
	void insert(tree& t, Node* p){//其中t必须用引用，因为if处更改了t。否则没有引用函数结束后复制的指针变量会被销毁，根节点指针无法创建二叉树。
		if(t==NULL)t=p;
		else if(p->data < t->data)insert(t->L,p);
		else insert(t->R,p);
	}
	tree& find(tree& t,const T& d){//返回以d为根结点的子树的根指针
		if(t==NULL)
			return t;//没找到
			else 	if(d==t->data)return t;//找到了
			else if(d<t->data)
				return find(t->L,d);
			else
				return find(t->R,d);
	}
	void travel(tree t)const{
		if(t!=NULL){
			travel(t->L);
			cout << t->data << ' ';
			travel(t->R);
		}
	}
	void clear(tree& t){
		if(t!=NULL){
			clear(t->L);
			clear(t->R);
			delete t;
			t=NULL;
		}
	}
	int high(tree t){
		if(t==NULL)return 0;
		int lh = high(t->L);
		int rh = high(t->R);
		return 1+(lh>rh?lh:rh);
	}
};
int main()
{
	bst b;
	b.insert('k');b.insert('s');b.insert('f');b.insert('t');
	b.insert('a');b.insert('m');b.insert('x');b.insert('e');
	b.insert('w');b.insert('b');b.insert('u');b.insert('j');
	b.insert('s');
	cout <<"The bst hight is:" << b.high(b.rt()) << endl;
	cout << "size:" << b.size() << endl;
	b.travel();
	b.remove('k');
	b.remove('m');
	b.remove('u');
	b.remove('j');
	cout <<"The bst hight is:" << b.high(b.rt()) << endl;
	b.travel();
	b.update('b','k');b.update('k','v');b.update('x','*');
	cout <<"The bst hight is:" << b.high(b.rt()) << endl;
	cout << "size:" << b.size() << endl;
	b.travel();
	cout <<"The bst hight is:" << b.high(b.rt()) << endl;
	while(!b.empty())b.remove(b.root());
	cout << "size:" << b.size() << endl;
	cout <<"The bst hight is:" << b.high(b.rt()) << endl;
	b.travel();
}
