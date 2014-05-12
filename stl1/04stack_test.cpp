#include<iostream>
using namespace std;
#include<string>
#include<typeinfo>
#include<cstring>
template< typename T=int,int len=10>
class Stack{
	T a[len];
	int cur;
public:
	const char* element()const{return typeid(T).name();}
	int max_size()const{return len;}
	Stack():cur(0){}
	void push(const T& d)throw(const char*){
		if(full())throw"满";
		a[cur++] = d;
	}//数据入stack成为stack顶
	T pop()throw(const char*){
		if(empty())throw"空";
		return a[--cur];
	}//stack顶数据出stack
	const T& top()const throw(const char*){
		if(empty())throw"空";
		return a[cur-1];
	}//取得stack顶数据
	bool empty()const{return cur==0;}//是否空
	bool full()const{return cur==5;}//是否已满
	void clear(){cur=0;}//栈清空（复位）
	int size()const{return cur;}//栈中数据个数
};
template <int len>
class Stack<const char*,len>{//部分特化
	string a[len];
	int cur;
public:
	const char* element()const{return "const char*";}
	int max_size()const{return len;}
	Stack():cur(0){}
	void push(string d)throw(const char*){
		if(full())throw"满";
		a[cur++] = d;
	}//数据入stack成为stack顶
	string pop()throw(const char*){
		if(empty())throw"空";
		return a[--cur].c_str();
	}//stack顶数据出stack
	const char*& top()const throw(const char*){
		if(empty())throw"空";
		return a[cur-1].c_str();
	}//取得stack顶数据
	bool empty()const{return cur==0;}//是否空
	bool full()const{return cur==len;}//是否已满
	void clear(){cur=0;}//栈清空（复位）
	int size()const{return cur;}//栈中数据个数
};
int main()
{
	Stack<int> i;
	i.push(1);i.push(2);i.push(3);
	while(!i.empty())cout << i.pop() << endl;
	char buf[100];
	Stack<const char*> s;
	for(;;){
		cin >> buf;
		if(strcmp(buf,"end")==0)break;
		s.push(buf);
	}
	cout << "===============" << endl;
	while(!s.empty())cout << s.pop() << endl;
}