#include<iostream>
using namespace std;
#include<string>
#include<typeinfo>
template< typename T,int len>
class Stack{
	T a[len];
	int cur;
public:
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
	cout << typeid(s).name() << endl;
	cout << typeid(d).name() << endl;
	s.push('+');s.push('-');s.push('*');s.push('/');
	while(!s.empty())
		cout << s.pop() << endl;
	d.push(100);d.push(65);d.push(7.189);d.push(12.3*4);
	while(!d.empty())
		cout << d.pop() << endl;
}