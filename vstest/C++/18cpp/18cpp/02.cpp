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
	static void Free(){
		if(instance_!=NULL){
			delete instance_;
		}
	}
	class Garbo{
	public:
		~Garbo(){
			if(Singleton::instance_!=NULL){
				delete instance_;
			}
		}
	};
private:
	Singleton& operator=(const Singleton& other);
	Singleton(const Singleton& other);
	Singleton(){
		cout << "Singleton..." << endl;
	}
	static Singleton* instance_;
	static Garbo garbo_;//���ö����ȷ��������
};
Singleton::Garbo Singleton::garbo_;
Singleton* Singleton::instance_;

int main(void){
	/*Singleton s1;
	Singleton s2;*/
	Singleton* s1=Singleton::GetInstance();
	Singleton* s2=Singleton::GetInstance();
	//Singleton::Free();
	//Singleton s3(*s1);//���ÿ������캯��
	//s3=s2;

	return 0;
}