#include <iostream>
using namespace std;
class Camera{
	double price;
public:
	void take(const char* obj){
		cout << "��" << obj << "����" << endl;
	}
	Camera(double p):price(p){cout<<"Camera()"<<endl;}
	~Camera(){cout<<"~Camera()"<<endl;}
	double getPrice(){return price;} 
};
class MP3{
	double price;
public:
	void play(const char* song){
		cout << "���Ÿ�����" << song << "��" << endl;
	}
	MP3(double p):price(p){cout<<"MP3()"<<endl;}
	~MP3(){cout<<"~MP3()"<<endl;}
	double getPrice(){return price;} 
};
class Phone{
	double price;
public:
	void dial(const char* no){
		cout << "��" << no << "����绰" << endl;
	}
	Phone(double p):price(p){cout<<"Phone()"<<endl;}
	~Phone(){cout<<"~Phone()"<<endl;}
	double getPrice(){return price;} 
};
class ModernPhone : public MP3,public Phone,public Camera
{
	string factory;
public:
	void visitnet(const char* url){
		cout << "������ַ" << url << endl;
	}
	ModernPhone(const char* factory,double price)
	:MP3(price),Phone(price),Camera(price),factory(factory){
		cout << "ModernPhone()" << endl;
	}
	~ModernPhone(){cout<<"~ModernPhone()"<<endl;}
};
int main()
{
	ModernPhone mp("nokia",500);
	mp.dial("110");
	mp.play("������ӭ��");
	mp.visitnet("bbs.tarena.com.cn");
	mp.take("��ɭ��");
	cout << mp.Phone::getPrice() << endl;
}
