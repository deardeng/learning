#include <iostream>
using namespace std;

class Animal{
public:
	Animal(){}
	virtual ~Animal(){}
	void play(){	eat();		shout();		sleep();}
	virtual void eat()=0;
	virtual void shout()=0;
	virtual void sleep()=0;
};
class Horse : public Animal{
public:
	Horse(){cout<<"��"<<endl;}
	~Horse(){cout<<"����"<<endl;}
	virtual void eat(){cout<<"��Բ�"<<endl;}
	virtual void shout(){cout<<"��˻"<<endl;}
	virtual void sleep(){cout<<"��վ��˯��"<<endl;}
};
class Tiger : public Animal{
public:
	Tiger(){cout<<"�ϻ�"<<endl;}
	~Tiger(){cout<<"���ϻ�"<<endl;}
	virtual void eat(){cout<<"�ϻ�����"<<endl;}
	virtual void shout(){cout<<"��Х"<<endl;}
	virtual void sleep(){cout<<"�ϻ�ſ��˯��"<<endl;}
};
int main()
{
	Animal* p = NULL;
	char choice;
	cout << "h--��, t--�ϻ�, ��ѡ��:";
	cin >> choice;
	if(choice=='h')		p = new Horse;
	else		p = new Tiger; 
	p->play();
	delete p;
//	Animal a;������
//	p = new Animal;������
	return 0;
}
