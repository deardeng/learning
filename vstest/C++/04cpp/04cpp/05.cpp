#include<iostream>
using namespace std;
//���ܷ��ؾֲ�����������

int& add(int a,int b){
	int sum;
	sum=a+b;
	return sum;
}
int main(void){
	int n=add(3,4);
	int& n2 = add(5,6);//n2�����ã�û���Լ������ĵ�ַ�ռ�
	//n2��ֵ�������������õı�����
	//���n2�����õı����������ڽ����ˣ�Ҳ����˵n2
	//��һ����Ч�����ã���ôn2��ֵ���ǲ�ȷ���ġ�
	cout << "n2=" << n2 << endl;
	cout << "n=" << n << endl;
	cout << "n2=" << n2 << endl;
	return 0;
}