#include<iostream>
using namespace std;
#include<typeinfo>
template <typename T>
class Type{
public:
	static string name(){return typeid(T).name();}
};
template <>
class Type<char>{
public:
	static string name(){return "char";};
};
template <>
class Type<int>{
public:
	static string name(){return "int";};
};
template <>
class Type<bool>{
public:
	static string name(){return "bool";};
};
template <typename T>
class Type<T*>{
public:
	static string name(){return Type<T>::name()+" pointer";}
};
template <typename T>
string type(T t)
{
	return Type<T>::name();
}

int main(){
	cout << type(123) << endl;
	cout << type(45.6) << endl;
	cout << type('x') << endl;
	int a=10;
	char b='k';
	cout << type(a/1.0) << endl;
	cout << type(a<b) << endl;
	cout << type(&a) << endl;
}