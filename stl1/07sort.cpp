#include<algorithm>
#include<iostream>
using namespace std;
using std::swap;
template <typename T>
void sort(T a[],int n){
	for(int i=1;i<n;i++){
		int min=i-1;
		for(int j=i;j<n;j++)
			if(a[j]<a[min])
				min=j;
			swap(a[min],a[i-1]);
	}
}
#include<cstring>
template<>
void sort(const char*a[],int n){
	for(int i=1;i<n;i++){
		int min=i-1;
		for(int j=i;j<n;j++)
			if(strcmp(a[j],a[min])<0)
				min=j;
			swap(a[min],a[i-1]);
	}
	cout << "==========const===========" << endl;
}
template<typename T>
void sort(T*a[],int n){
	for(int i=1;i<n;i++){
		int min=i-1;
		for(int j=i;j<n;j++)
			if(*a[j]<*a[min])
				min=j;
			swap(a[min],a[i-1]);
	}
	cout << "==========T* a[]===========" << endl;
}
#include<iostream>
using namespace std;
struct Date{
	int y,m,d;
	Date(int y,int m,int d):y(y),m(m),d(d){}
};
bool operator<(const Date& a,const Date& b){
	if(a.y<b.y||a.y==b.y&&a.m<b.m||a.y==b.y&&a.m==b.m&&a.d<b.d)
		return true;
	else 
		return false;
	//return (a.y<b.y||a.y==b.y&&a.m<b.m||a.y==b.y&&a.m==b.m&&a.d<b.d)
}
ostream& operator<<(ostream& o,const Date& d){
	return o << d.y << '-' << d.m << '-' << d.d;
};
template<typename T>
void show(T a[],int n){
	for(int i=0;i<n;i++)
		cout << a[i] << ' ';
	cout << endl;
}
template<typename T,int N>
void show_char(T(& t)[N]){//数组引用
	for(int i=0;i<N;i++)
		cout << t[i] << ' ';
	cout << "=====T(& t)[N]====="<< endl;
}
template<typename T,int N>
void show(T*(& t)[N]){
	for(int i=0;i<N;i++)
		cout << *t[i] << ' ';
	cout << "=====T*(& t)[N]====="<< endl;
}
// void show(T& t){
// 	int n=sizeof(t)/sizeof(t[0]);
// 	for(int i=0;i<n;i++)
// 		cout << t[i] << ' ';
// 	cout << endl;
// }
template<typename T>
void show(T data){
	cout << data << endl;
}
int main()
{
	double m=123.4;
	show(m);
	int a[5]={6,1,9,2,8};
	double d[4]={3.3,5.5,2.2,1.6};
	Date x[3]={{2010,8,8},{2011,9,1},{2010,9,10}};
	Date y(2014,3,7);
	sort(a,5);//a==>int*
	//sort(reinterpret_cast<int*>(d),4);
	sort(d,4);
	if(x[1]<x[2])
		cout << x[1];
	else
		cout << x[2];
	cout << endl;
	sort(x,3);
	show(d,4);
	show(a,5);
	show(x,3);
	show(d);
	show(a);
	show(x);
	const char* s[3]={"furong","quange","chunge"};
	sort(s,3);
	show_char(s);
	int* ap[4]={new int(5),new int(2),new int(9),new int(8)};
	double* dp[3]={new double(3.3),new double(5.5),new double(2.2)};
	sort(ap,4);
	sort(dp,3);
	show(ap);show(dp);
}