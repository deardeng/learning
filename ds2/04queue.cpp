#include<iostream>
using namespace std;

typedef int T;
#include"01list.h"
class Queue{
	List l;
public:
	Queue& push(const T& d){l.push_back(d);return *this;}
	T pop(){T t=front();l.erase(0);return t;}
	const T& front()const {return l.front();}
	const T& back()const {return l.back();}
	int size()const{return l.size();}
	void clear(){l.clear();}
	bool empty()const{return l.empty();}
	bool full()const{return false;}
};
int main(){
	Queue q;
	q.push(1).push(2).push(3);
	q.push(4).push(5);
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	q.push(6).push(7).push(8);
	while(!q.empty())
		cout << q.pop() << endl;
}