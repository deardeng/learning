#include <iostream>
using namespace std;

//const_cast�����Ƴ�������
//const_castһ����˵��ָ���������
//const_castȥ�������Բ���Ϊ���޸�����ָ�������
//const_castȥ����������Ϊ�˺����ܽ���ʵ��
void fun(int &val){
	cout << "fun" << val << endl;
}
int main(void){
	const int val=100;
	//int n=const_cast<int> (val);
	int n=val; 
	int *p=const_cast<int*>(&val);
	*p=200;
	printf("val=%p\n",val);
	printf("p=%p\n",p);
	cout << &val << endl;
	cout << p << endl;
	cout << "val=" << val << endl;


	const int val2=200;
	int& refval2=const_cast<int&>(val2);
	refval2=300;
	cout << "val2=" << val2 <<  endl;

	fun(const_cast<int&>(val2));
 	return 0;
}