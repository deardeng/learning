#include <iostream>
using namespace std;
//const ������ָ��const���������
int main(void){
	const int val=1024;
	const int& refval=val;
	//int& ref2=val;//Error,nonconst reference to const
	//ref2=200;//���������ȷ���˾�Ϸ�������ζ�ſ��Ըı䳣����
	int val2=1024;
	const int& ref3=val2;//const reference to nonconst object
	double val3=3.14;
	const int& ref4=val3;//int temp = val3;const int& ref4=temp;
	cout << "ref4=" << ref4 << endl;
	cout << "val3=" << val3 << endl;
	
	//int& ref5 =val3;//Error ������ô�ȼ۵ģ�int temp = val3;const int& ref4=temp;
	return 0;
}