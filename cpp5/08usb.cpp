#include <iostream>
using namespace std;

class USB{
public:
	virtual void plugin(){cout<<"ʶ���豸"<<endl;}
	virtual void work(){cout<<"���豸��������"<<endl;}
	virtual void stop(){cout<<"���豸ֹͣ����"<<endl;}
};
class USBDisk : public USB{
public:
	void plugin(){cout<<"�������豸��USB����"<<endl;}
	void work(){cout<<"�Ѵ����ϵ��ļ������Ƶ�Ӳ����"<<endl;}
	void stop(){cout<<"ֹͣ�Դ��̵ķ���"<<endl;}
};
class USBFan : public USB{
public:
	void plugin(){cout<<"�������豸��USB����"<<endl;}
	void work(){cout<<"�÷���ת�����ͳ���ˬ"<<endl;}
	void stop(){cout<<"�÷���ͣת"<<endl;}
};
class Computer{
public:
	void use(USB* p){
		p->plugin();
		p->work();
		p->stop();
	}
};
class USBCamera : public USB{
public:
	void plugin(){cout<<"�������豸��USB����ͷ"<<endl;}
	void work(){cout<<"��ʼ����Դ�����Ƶ"<<endl;}
	void stop(){cout<<"ֹͣ�ɼ���Ƶ"<<endl;}
};
int main()
{
	USBDisk d;
	USBFan f;
	Computer c;
	c.use(&d);
	c.use(&f);
	USBCamera a;
	c.use(&a);
}
