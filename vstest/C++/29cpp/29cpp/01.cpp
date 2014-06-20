#include <iostream>
using namespace std;

class Base{
public:
	int x_;
protected:
	int y_;
private:
	int z_;
};

class PublicInherit:public Base{
public:
	void Test(){
		x_=10;
		y_=20;
		//z_=30;
	}
private:
	int a_;
};
class PrivateInherit:private Base{
public:
	void Test(){
		x_=10;
		y_=20;
		//z_=30;
	}
};
class PublicProtectedInherit:public PublicInherit{
public:
	void Test(){
		y_=30;
	}
};
int main(void){
	PublicInherit pub;
	pub.x_=20;
	return 0;
}