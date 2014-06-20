#include "Test.h"
#include <iostream>
using namespace std;

//���������Ĺ��캯����ΪĬ�Ϲ��캯��
Test::Test(){
	num_ = 0;
	cout << "Initializing Default" << endl;
}
Test::Test(int num){
	num_=num;
	cout << "Initializing " << num_ << endl;
}
Test::~Test(){
	cout << "Destroy" << num_ << endl;
}
void Test::Display(){
	cout << "num=" << num_ << endl;
}
Test& Test::operator=(const Test& other){
	if(this == &other)
		return *this;
	num_=other.num_;
	cout << "Test::operator=" << endl;
	return *this;
}