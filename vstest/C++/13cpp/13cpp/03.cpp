#include <iostream>
using namespace std;


class Object{
public:
	enum E_TYPE{
		TYPE_A=100,
		TYPE_B=200
	};
public:
	Object(int num=0):num_(num),kNum_(num),refNum_(num_){
		//kNum_=100;
		cout << "Object" << num_ << "..." << endl;
	}
	~Object(){
		cout << "~Object" << num_ << "..." << endl;
	}
	void DisplayKNum(){
		cout << "kNum=" << kNum_ << endl;
	}
private:
	int num_;
	const int kNum_;
	int& refNum_;
};


int main(void){
	Object obj1(10);
	Object obj2(20);
	obj1.DisplayKNum();
	obj2.DisplayKNum();
	cout << obj1.TYPE_A << endl;
	cout << obj2.TYPE_A << endl;
	cout << Object::TYPE_A << endl;
	return 0;
}