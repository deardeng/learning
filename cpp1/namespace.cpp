#include <iostream>
using namespace std;
#include <string>
namespace czq{
	string name="����Ȩ";
	int age = 40;
}
namespace furong{
	char name[20]="ܽ�ؽ��";
	double salary = 8000;
}
using namespace czq;
using namespace furong;
char name[20]="����";
int main()
{
	//cout << "��ϲ��" << name << endl;//���壺Ȩ�磿ܽ�أ�
	cout << "����" << czq::name << ",����" << age << endl;
	cout << "����" << furong::name << ",��н" << salary << endl;
	string name = "������";
	cout << name << "��˧" << endl;//�ڲ���name��������
	cout << ::name << "Ҳ��˧" << endl;//ȫ�ֵ�name������
	return 0;
}

