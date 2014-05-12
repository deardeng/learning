/*set的个性：
 * 元素就是key
 * 不允许重复key
 */ 
#include<set>
#include<iostream>
using namespace std;
#include<string>
#include"print.h"
#include<fstream>

int main(){
	set<string> ss;
	//set<char*> ss;
	string s;
	//char s[100];
	ifstream fin("maillist");
	if(!fin)return 1;
	while(fin >> s) ss.insert(s);
	print(ss.begin(),ss.end(),'\n');
}