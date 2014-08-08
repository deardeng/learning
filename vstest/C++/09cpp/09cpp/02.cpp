#include <iostream>
using namespace std;

struct Test2{
	int x_;
	int y_;
	int z_;
	void Init(int x,int y,int z){
		x_=x;
		y_=y;
		z_=z;
	}
	void Display(){
		cout << "x=" << x_ << " y=" << y_ << " z=" << z_ 
			<< endl;
	}
};
class Test3{
public:
	int x_;
	int y_;
	int z_;
	void Init(int x,int y,int z){
		x_=x;
		y_=y;
		z_=z;
	}
	void Display(){
		cout << "x=" << x_ << " y=" << y_ << " z=" << z_ 
			<< endl;
	}
};
int main(void){
	/*Test2 t;
	t.Init(10,20,30);
	t.Display();*/
	/*Test2 t2={10,20,30};
	t2.Display();*/
	//Test3 t3;
	//t3.Init(10,20,30);
	Test3 t3={10,20,30};
	t3.Display();
	return 0;
}