#include <iostream>
using namespace std;
#include <cstdlib>
//static_cast��ֵ����֮�䣬��һ����void*��ָ������֮��
//const_cast������ʱȥ��const��volatile����
//reinterpret_cast��������ָ������֮�䣬ָ������ֵ����֮��
//dynamic_cast�Ժ��ٽ�
int main()
{
	int n = static_cast<int>(45.67);
	int* p = static_cast<int*>(calloc(sizeof(int),10));
	free(p);
	const int k = n;
	cout << "k=" << k << endl;
	const_cast<int&>(k) = 789;
	cout << "k=" << k << endl;
	float f=123.45;
	p = reinterpret_cast<int*>(&f);
	cout << *p << endl;
	n = int(12.34);
	cout << "n=" << n << endl;
	n = int();
	cout << "n=" << n << endl;
	int m(100);
	cout << "m=" << m << endl;
	int x();//��������
	int(y)=200;//�������ã����׸�ǿ������ת������
	cout << "y=" << y << endl;
}
