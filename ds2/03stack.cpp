#include<iostream>
using namespace std;
#include<string>
typedef int T;
#include"01list.h"

class Stack{
	List l;//组合
public:
	void push(const T& d);//数据入stack成为stack顶
	T pop();//stack顶数据出stack
	const T& top()const;//取得stack顶数据
	bool empty()const{return l.empty();}//是否空
	bool full()const{return false;}//是否已满
	void clear(){l.clear();}//栈清空（复位）
	int size()const{return l.size();}//栈中数据个数
};
void Stack::push(const T&d){
	l.push_front(d);
}
T Stack::pop(){
	T t = l.front();
	l.erase(0);
	return t;
}
const T& Stack::top()const {
	return l.front();
}
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	while(!s.empty()){
		cout << s.pop() << endl;
	}
	try{
		s.pop();
	}
	catch(const char* e){
		cout << e << endl;
	}
}