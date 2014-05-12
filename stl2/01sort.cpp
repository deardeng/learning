#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
class Person{
	string name;
	int age;
public:
	Person(const char * name,int age):name(name),age(age){}
	friend ostream& operator<<(ostream& o,const Person& p){
		o << p.name << ':' << p.age;
	}
	friend bool operator<(const Person& a,const Person& b){
		return a.age < b.age;
	}
};
template<typename T>
void print(T b, T e)
{
	while(b!=e){
		cout << *b++ << ' ';
	}
	cout << endl;
}

int main()
{
	int a[6]={8,1,6,3,2,5};
	double b[4]={5.5,3.3,6.6,2.2};
	string c[5]={"nice","to","see","you","all"};
	Person d[3]={Person("芙蓉",18),Person("杨强",20),Person("薇薇",16)};
	sort(a,a+6);sort(b,b+4);sort(c,c+5);sort(d,d+3);//区间,起始位置，超越终点位置
	print(a,a+6);print(b,b+4);print(c,c+5);print(d,d+3);
}