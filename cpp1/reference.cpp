#include <iostream>
using namespace std;

int main()
{
	double d = 123.45;
	double& e = d;//e��d�ı�����������ͬһ������
	//double*const E=&d;�����e���൱��*E
	//double& f = 123.45;//����ֻ���ñ�������ʼ��
	const double& c = 234.56;
	const double& s = d+5;
	cout << "&d=" << &d << ", &e=" << &e << endl;
	//int& n = d;//���Ͳ�һ��
	cout << "d=" << d << ",e=" << e << "c=" << c << "s=" << s << endl;
	double& e2 = e;
	cout << "&e2=" << &e2 << ", e2=" << e2 << endl;
	e2 = 78.9;
	cout << "d=" << d << ", e=" << e << endl;
}

