#include <iostream>
using namespace std;

class Singleton{
public:
	static Singleton& GetInstance(){
		static Singleton instance;//局部静态对象
		return instance;
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


int main(void){

	Singleton& s1=Singleton::GetInstance();
	Singleton& s2=Singleton::GetInstance();

	return 0;
}