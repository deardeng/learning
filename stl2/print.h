#ifndef PRINT_H
#define PRINT_H 1
//输出一个指定区间中的所有数据（含头不含尾）
#include<iostream>
using namespace std;
template<typename T>
void print(T b, T e,char c=' ')
{
	while(b!=e){
		cout << *b++ << c;
	}
	cout << endl;
}
#endif