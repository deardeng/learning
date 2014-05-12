#include<iostream>
using namespace std;
#include<typeinfo>
template <int n>
class Fact{
public:
	enum {val=Fact<n-1>::val*n};
};
template<>
class Fact<0>{
public:
	enum {val=1};
};
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
int main(){
	cout << Fact<5>::val << endl;
	cout << Type<double>::name() << endl;
	cout << Type<char>::name() << endl;
	cout << Type<float>::name() << endl;
	cout << Type<int**>::name() << endl;
}