#include <iostream>//input/output stream
#include <string>
using std::cout;//A::B��ʾA��Χ�ڵ�B����::����Ϊ�������
using std::cin;
using std::string;
using std::endl;
int main()
{
	cout << "��������������������:\n";
	string name;
	int age;
	cin >> name >> age;
	cout << name << "���ã���������" << 2010-age << "��"
		<< endl;//end line==>'\n'
//	return 0;//main����ĩβ��return 0���п���
}

