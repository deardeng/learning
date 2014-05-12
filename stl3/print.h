#ifndef PRINT_H
#define PRINT_H 1
#include<iostream>
using namespace std;
template<typename T>
void print(T b, T e,char c=' ')
{
	while(b!=e){
		cout << *b++ << c;
	}
	if(c!='\n')
	cout << endl;
}
template<typename K,typename V>
ostream& operator<<(ostream& o,const pair<K,V>& p){
	return o << p.first << ':' << p.second;
}
#endif