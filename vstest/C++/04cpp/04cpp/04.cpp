#include<iostream>
using namespace std;
//������Ϊ��������
int a[]={0,1,2,3,4};
int& index(int i){
	return a[i];
}
int main(void){
	index(3)=100;//������Ϊ��������ֵ��ʹ��
	//�������Է��ڸ�ֵ��������
	//�����������ã������ں�������ʱ���ʼ��
	//index(3)�ں������ص�ʱ�򱻳�ʼ��Ϊa[3]
	cout << "a[3]=" << a[3] << endl;
	return 0;
}