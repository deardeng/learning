#include <iostream>
using namespace std;

//����һ��û���κνӿڵ��࣬�����Ҫ���������
//�����ֻ࣬�ܽ���������������Ϊ�����
//ͨ��������ڻ����д��麯������Ҫʵ��
//�����Ǵ�����������Ҫ����ʵ�֡�������һ���յ�ʵ�ּ��ɣ�
class Base{
public:
	virtual ~Base()=0{

	}
};
class Drived : public Base{

};
int main(void){
	Drived d;
	return 0;
}