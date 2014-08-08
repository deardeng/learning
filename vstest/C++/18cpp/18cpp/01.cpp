#include <iostream>
using namespace std;

class Singleton{
public:
	static Singleton* GetInstance(){
		if(instance_==NULL){
			instance_=new Singleton;
		}
		return instance_;
	}
	~Singleton(){
		cout << "~Singleton..." << endl;
	}
private:
	Singleton& operator=(const Singleton& other);
	Singleton(const Singleton& other);
	Singleton(){
		cout << "Singleton..." << endl;
	}
	static Singleton* instance_;
};
Singleton* Singleton::instance_;
int main(void){
	/*Singleton s1;
	Singleton s2;*/
	Singleton* s1=Singleton::GetInstance();
	Singleton* s2=Singleton::GetInstance();
	Singleton s3(*s1);//调用拷贝构造函数
	s3=s2;

	return 0;
}