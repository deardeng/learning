#include <iostream>
using namespace std;

class Animal{
public:
	Animal(){sleep();}
	virtual ~Animal(){shout();}
	void play(){	eat();		shout();		sleep();}
	virtual void eat(){cout<<"³Ô"<<endl;}
	virtual void shout(){cout<<"½Ð"<<endl;}
	virtual void sleep(){cout<<"Ë¯"<<endl;}
};
class Horse : public Animal{
public:
	Horse(){cout<<"Âí"<<endl;}
	~Horse(){cout<<"ËÀÂí"<<endl;}
	virtual void eat(){cout<<"Âí³Ô²Ý"<<endl;}
	virtual void shout(){cout<<"ÂíË»"<<endl;}
	virtual void sleep(){cout<<"ÂíÕ¾×ÅË¯¾õ"<<endl;}
};
class Tiger : public Animal{
public:
	Tiger(){cout<<"ÀÏ»¢"<<endl;}
	~Tiger(){cout<<"ËÀÀÏ»¢"<<endl;}
	virtual void eat(){cout<<"ÀÏ»¢³ÔÈâ"<<endl;}
	virtual void shout(){cout<<"»¢Ð¥"<<endl;}
	virtual void sleep(){cout<<"ÀÏ»¢Å¿×ÅË¯¾õ"<<endl;}
};
int main()
{
	Animal* p = NULL;
	char choice;
	cout << "h--Âí, t--ÀÏ»¢, ÇëÑ¡Ôñ:";
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
