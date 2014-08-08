#include <iostream>
using namespace std;

class Outer{
public:
	class Inner{
	public:
		void Fun();/*{
			cout << "Inner::Fun..." << endl;
		}*/
	};
public:
	Inner obj_;
	void Fun(){
		cout << "Outer::Fun..." << endl;
		obj_.Fun();
	}
};
void Outer::Inner::Fun(){
	cout << "Inner::Fun..." << endl;
}
void Fun(){
	class LocalClass{
	public:
		int num_;
		void Init(int num){
			num_ = num;
		}
		void Display(){
			cout << "num=" << num_ << endl;
		}
		//static int num2_;
	};
	LocalClass lc;
	lc.Init(10);
	lc.Display();
}
int main(void){
	Outer o;
	o.Fun();
	Outer::Inner i;
	i.Fun();
	Fun();
	//LocalClass lc; Error,局部类只能在定义它的函数体中使用
	return 0;
}