#include <iostream>
using namespace std;
#include <string>
//i����.getline(char����,�����С);������ܶ���һ���л����ô���״̬
//getline(i����,string��������);���ǳ�Ա����������ȫ�ֺ���
//�������汾�������õ���������ָ������ʲô�ַ�Ϊֹ��Ĭ����'\n'
int main()
{
	char buf[10];
	if(!cin.getline(buf,sizeof(buf))){
		cout << "�����г���\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	string s;
	getline(cin, s, '~');
	cout << "buf=[" << buf << "]\n";
	cout << "s=[" << s << "]\n";
	printf("%s\n", s.c_str());
}
