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
class ModernPhone : public MP3,public Phone,public Camera
{
	string factory;
public:
	void visitnet(const char* url){
		cout << "������ַ" << url << endl;
	}
	ModernPhone(const char* factory,double p)
	:Camera(p-2),MP3(p-1),Phone(p-3),factory(factory),Goods(p)
	{		cout << "ModernPhone()" << endl;	}
	~ModernPhone(){cout<<"~ModernPhone()"<<endl;}
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
