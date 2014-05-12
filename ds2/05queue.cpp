#include<iostream>
using namespace std;

typedef int T;
class Queue{
	T a[5];
	int b,n;//队首位置和有效元素个数
public:
	Queue():b(0),n(0){}
	Queue& push(const T&d){
		if(full())throw "满";
		a[(b+n++)%5] = d;
		return *this;
	}
	T pop(){
		if(empty())throw "空";
		--n;
		T& t = a[b];//
		if(++b==5)b=0;//
		return t;//return a[b++%5];
		
	}
		const T& front()const {return a[b%5];}
		const T& back()const {return a[(b+n-1)%5];}
		int size()const{return n;}
		void clear(){b=0,n=0;}
		bool empty()const{return n==0;}
		bool full()const{return n==5;}
};
int main(){
	Queue q;
	try{
		q.push(1).push(2).push(3);
		q.push(4).push(5);
		cout << q.pop() << endl;
		cout << q.pop() << endl;
		q.push(6).push(7).push(8);
	}
	catch(const char* e){
		cout << "异常：" << e << endl;
	}
	while(!q.empty())
		cout << q.pop() << endl;
}