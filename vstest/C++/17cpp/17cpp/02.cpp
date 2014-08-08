#include <iostream>
using namespace std;

class Test{
public:
	Test(int n):n_(n){
		cout << "Test" << n_ << "..." << endl;
	}
	~Test(){
		cout << "~Test" << n_ << "..." << endl;
	}
private:
	int n_;
};
int n;		//δ��ʼ����ȫ�ֱ�������ʼֵΪ0��n�洢��.bss���С�(block started by symbol)
int n2=100;	//�ѳ�ʼ����ȫ�ֱ�������ʼֵΪ100��n2�洢��.data���С�
Test g(100);//ȫ�ֶ���Ĺ�������main����
static Test g2(200);

int main(void){
	cout << "Entering main..." << endl;
	cout << n << endl;
	Test t(10);		//ջ�ϴ����Ķ����������ڽ�����ʱ���Զ��ͷ�
	{
		Test t(20);
	}
	{

		Test *t3 = new Test(30);//���ϴ����Ķ���Ҫ��ʾ�ͷ�
		delete t3;
	}
	{
		static int n3;			//n3�洢��.bss���У������ڳ�ʼ��
		static int n4 = 100;	//n4�洢��.data���У������ڳ�ʼ��

		static Test t4(333);	//t4�����������ڳ�ʼ�����洢��.data����
	}
	cout << "Exit main..." << endl;
}