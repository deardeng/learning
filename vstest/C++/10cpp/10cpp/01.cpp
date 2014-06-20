#include <iostream>
using namespace std;

class Test{
public:
	int num_;
};
int num_ =20;
int add(int a,int b);
int test();
int main(void){
	int num_=30;
	{
		int num_ = 100;
	}
	cout << num_ << endl;
	cout << ::num_ << endl;
	test();
	return 0;
}
int add(int a,int b){
	return a+b;
}

int test(){
LABEL1:
	cout << "label1" << endl;
	goto LABEL3;
LABEL2:
	cout << "label2" << endl;
	goto LABEL1;
LABEL3:
	cout << "lable3" << endl;
	goto LABEL2;
}