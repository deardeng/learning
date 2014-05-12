#include<iostream>
using namespace std;
#include<string>
#include<typeinfo>
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
int main()
{
	Stack<char,20> s;
	Stack<double,30> d;
	Stack<float> f;
	Stack<> a;
	s.push('+');s.push('-');s.push('*');s.push('/');
	cout << s.size() << '/' << s.max_size() << ':' <<
	s.element() << endl;
	cout << d.size() << '/' << d.max_size() << ':' <<
	d.element() << endl;
	cout << f.size() << '/' << f.max_size() << ':' <<
	f.element() << endl;
	cout << a.size() << '/' << a.max_size() << ':' <<
	a.element() << endl;
}