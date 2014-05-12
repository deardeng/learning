#include <iostream>
using namespace std;
class Goods{
	double price;
public:
	Goods(double p=123.45):price(p){
		cout << "Goods("<<p<<")"<<endl;
	}
	~Goods(){cout<<"~Goods()"<<endl;}
	double getPrice(){return price;}
};
class Camera:virtual public Goods{
public:
	void take(const char* obj){
		cout << "��" << obj << "����" << endl;
	}
	Camera(double p):Goods(p){cout<<"Camera()"<<endl;}
	~Camera(){cout<<"~Camera()"<<endl;}
};
class MP3:virtual public Goods{
public:
	void play(const char* song){
		cout << "���Ÿ�����" << song << "��" << endl;
	}
	MP3(double p):Goods(p){cout<<"MP3()"<<endl;}
	~MP3(){cout<<"~MP3()"<<endl;}
};
class Phone:virtual public Goods{
public:
	void dial(const char* no){
		cout << "��" << no << "����绰" << endl;
	}
	Phone(double p):Goods(p){cout<<"Phone()"<<endl;}
	~Phone(){cout<<"~Phone()"<<endl;}
};
class ModernPhone : public Phone
{//���
	string factory;
	Goods g;
	Camera c;
	MP3 m;
public:
	void visitnet(const char* url){
		cout << "������ַ" << url << endl;
	}
	ModernPhone(const char* factory,double p)
	:m(p),c(p),Phone(p),factory(factory),g(p)
	{		cout << "ModernPhone()" << endl;	}
	~ModernPhone(){cout<<"~ModernPhone()"<<endl;}
	void take(const char* obj){c.take(obj);}
	void play(const char* song){m.play(song);}
	double getPrice(){return g.getPrice();}
};
int main()
{
	ModernPhone mp("nokia",500);
	mp.dial("110");
	mp.play("������ӭ��");
	mp.visitnet("bbs.tarena.com.cn");
	mp.take("��ɭ��");
	cout << mp.getPrice() << endl;
}
