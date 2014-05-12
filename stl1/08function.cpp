#include<iostream>
using namespace std;
#include<cstring>
template<typename T>
const T& Min(const T& a,const T& b){
	cout << 'A';
	return a<b?a:b;
}
template<typename T>
T& Min(T& a,T& b){
	cout << 'B';
	return a<b?a:b;
}
template<typename T,typename U>
T Min(const T&a,const U& b){
	cout << 'C';
	return a<b?a:T(b);
}
const char* Min(const char* a,const char* b){
	cout << 'D';
	return strcmp(a,b)<0?a:b;
}
template<typename T>
T Min(const T& a,char b){
	cout << 'E';
	return a<b?a:T(b);
}
template<>
double& Min(double& a,double& b){
	cout << 'F';
	return a<b?a:b;
}
int main(){
	int m=20,n=10;
	double x=1.1,y=2.2;
	cout << Min(m,n) << endl;
	cout << Min(x,y) << endl;
	cout << Min(30,40) << endl;
	cout << Min(5.9,6) << endl;
	cout << Min("hello","world") << endl;
	cout << Min<>("hello","world") << endl;
	cout << Min(123,'x') << endl;
	cout << Min('x',123) << endl;
}