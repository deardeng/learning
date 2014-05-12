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
	Horse(){cout<<"马"<<endl;}
	~Horse(){cout<<"死马"<<endl;}
	virtual void eat(){cout<<"马吃草"<<endl;}
	virtual void shout(){cout<<"马嘶"<<endl;}
	virtual void sleep(){cout<<"马站着睡觉"<<endl;}
};
class Tiger : public Animal{
public:
	Tiger(){cout<<"老虎"<<endl;}
	~Tiger(){cout<<"死老虎"<<endl;}
	virtual void eat(){cout<<"老虎吃肉"<<endl;}
	virtual void shout(){cout<<"虎啸"<<endl;}
	virtual void sleep(){cout<<"老虎趴着睡觉"<<endl;}
};
int main()
{
	Animal* p = NULL;
	char choice;
	cout << "h--马, t--老虎, 请选择:";
	cin >> choice;
	if(choice=='h')		p = new Horse;
	else		p = new Tiger; 
	p->play();
	delete p;
//	Animal a;不允许
//	p = new Animal;不允许
	return 0;
}
