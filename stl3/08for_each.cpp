#include<iostream>
#include<algorithm>
using namespace std;
#include<string>
void add10(int& element){
	element += 10;
}

string print(int element){
	cout << element << ' ';
	return "芙蓉";
}
class add{
	int delta;
public:
	add(int d):delta(d){}
	void operator()(int& element){
		element += delta;
	}
};
template<typename Iter,typename Func>
void foreach(Iter ib,Iter ie,Func f){
	while(ib!=ie)f(*ib++);
}
int main(){
	int a[5] = {11,22,33,44,55};
	foreach(a,a+5,add10);
	foreach(a,a+5,print);	cout << endl;
	foreach(a,a+5,add(3));
	foreach(a,a+5,print);	cout << endl;
	foreach(a,a+5,add(1));
	foreach(a,a+5,print);	cout << endl;
}