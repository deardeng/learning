#include <iostream>
using namespace std;

class Animal{
public:
	Animal(){sleep();}
	virtual ~Animal(){shout();}
	void play(){	eat();		shout();		sleep();}
	virtual void eat(){cout<<"��"<<endl;}
	virtual void shout(){cout<<"��"<<endl;}
	virtual void sleep(){cout<<"˯"<<endl;}
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
	cout << "=================" << endl;
	p->Animal::eat();
	cout << "=================" << endl;
	delete p;
	return 0;
}
