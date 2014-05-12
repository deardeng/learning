#include <iostream>
using namespace std;
#include <string>
#include <fstream>

int main()
{
	string path = "04cerr.cpp";
	ifstream fin(path.c_str());
	ofstream fout("04copy");
	/*	ifstream fin;	fin.open(path.c_str());	*/
	if(!fin){
		cout << "打开文件" << path << "失败" << endl;
		return 1;
	}
	if(!fout){
		cout << "打开04copy文件失败" << endl;
		return 2;
	}
	char ch;
	while(fin.get(ch)){//用while(fin>>ch)会跳过所有空白字符 
		cout << ch; fout << ch;
	}
//	while(fin){fin.get(ch);fout<<ch;}这样复制最后会多一个字符
	fin.clear();
	fin.close();
	fout.close();
	return 0;
}
