#include <iostream>
using namespace std;
class Camera{
	double price;
public:
	void take(const char* obj){
		cout << "给" << obj << "照相" << endl;
	}
	Camera(double p):price(p){cout<<"Camera()"<<endl;}
	~Camera(){cout<<"~Camera()"<<endl;}
	double getPrice(){return price;} 
};
class MP3{
	double price;
public:
	void play(const char* song){
		cout << "播放歌曲《" << song << "》" << endl;
	}
	MP3(double p):price(p){cout<<"MP3()"<<endl;}
	~MP3(){cout<<"~MP3()"<<endl;}
	double getPrice(){return price;} 
};
class Phone{
	double price;
public:
	void dial(const char* no){
		cout << "给" << no << "拨打电话" << endl;
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
		cout << "访问网址" << url << endl;
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
	mp.play("北京欢迎你");
	mp.visitnet("bbs.tarena.com.cn");
	mp.take("康森林");
	cout << mp.Phone::getPrice() << endl;
}
