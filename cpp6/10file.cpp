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
		cout << "���ļ�" << path << "ʧ��" << endl;
		return 1;
	}
	if(!fout){
		cout << "��04copy�ļ�ʧ��" << endl;
		return 2;
	}
	char ch;
	while(fin.get(ch)){//��while(fin>>ch)���������пհ��ַ� 
		cout << ch; fout << ch;
	}
//	while(fin){fin.get(ch);fout<<ch;}�������������һ���ַ�
	fin.clear();
	fin.close();
	fout.close();
	return 0;
}
