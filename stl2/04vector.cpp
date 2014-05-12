/*vector的个性：
 * .capacity()目前分配的容量（当前容量）.size()实际用了的个数
 * 约定容量：.reserve(n)
 * 下标[]：.operator[](i),.at(i)越界抛出异常
 */
#include<iostream>
using namespace std;
#include<vector>
#include"print.h"
#include<exception>
#include<typeinfo>

int main(){
	vector<double> vd,vv;
	for(int i=0;i<9;i++){
		vd.push_back(i+0.1);
		cout << &*vd.begin() << ':';
		cout << vd.size() << '/' << vd.capacity() << endl;
	}
	cout << "======================" << endl;
	vv.reserve(9);
	
	for(int i=0;i<9;i++){
		vv.push_back(i+0.5);
		cout << vv.size() << '/' << vv.capacity() << endl;
	}
	vd[3]=123.45;
	vv.at(5)=67.8;
	for(int i=0;i<=vd.size();i++)
		cout << vd[i] << ' ';
	cout << endl;
	try{
		for(int i=0;i<=vd.size();i++)
			cout << vv.at(i) << ' ';
		cout << endl;
	}catch(exception& e){
		cout << "异常：" << e.what() << endl;
		cout << "类型：" << typeid(e).name() << endl;
	}
	int m=3,n=5;
	void print(const vector< vector<int> >& v);
	vector<vector<int> > vvi(m,vector<int>(n));
	print(vvi);
	cout << "==================" << endl;
	vvi.resize(m+3);
	vvi[1].assign(9,1);
	vvi[5].assign(4,5);
	print(vvi);
}
void print(const vector<vector<int > >& v)
{
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}

template<typename T>
void show(T a[],int n);
template<typename T>
void show(const vector<int>& v);//v.size()