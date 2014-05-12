#include<iostream>
using namespace std;
#include<string>
#include<typeinfo>
template< typename T>
class Stack{
	T a[50];
	int cur;
public:
	Stack():cur(0){}
	void push(const T& d)throw(const char*);//数据入stack成为stack顶
	T pop()throw(const char*);//stack顶数据出stack
	const T& top()const throw(const char*);//取得stack顶数据
	bool empty()const{return cur==0;}//是否空
	bool full()const{return cur==5;}//是否已满
	void clear(){cur=0;}//栈清空（复位）
	int size()const{return cur;}//栈中数据个数
};
template < typename T>
void Stack<T>::push(const T&d)throw(const char*){
	if(full())throw"满";
	a[cur++] = d;
}
template < typename T>
T Stack<T>::pop()throw(const char*){
	if(empty())throw"空";
	return a[--cur];
}
template < typename T>
const T& Stack<T>::top()const throw(const char*){
	if(empty())throw"空";
	return a[cur-1];
}
int main()
{
	Stack<char> s;
	Stack<double> d;
	Stack<char> c;
	cout << typeid(s).name() << endl;
	cout << typeid(d).name() << endl;
	//s=d;错误：s和d是不同类型的
	//s = c;
	s.push('+');s.push('-');s.push('*');s.push('/');
	while(!s.empty())
		cout << s.pop() << endl;
	d.push(100);d.push(65);d.push(7.89);d.push(12.3*4);
	while(!d.empty())
		cout << d.pop() << endl;
}