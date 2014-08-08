#include "Complex.h"
#include <iostream>
using  namespace std;
Complex::Complex()
{
	//cout << "***" << endl;
}
Complex::Complex(const Complex& o){
	cout << "***" << endl;
	*this=o;
}

Complex::~Complex()
{
}
Complex::Complex(int real,int imag):real_(real),imag_(imag){cout << "..." << endl;}

Complex& Complex::Add(const Complex& other){
	real_+=other.real_;
	imag_+=other.imag_;
	return *this;
}

void Complex::Display()const{
	cout << real_ << '+' << imag_ << endl;
}

Complex Complex::operator+(const Complex& other){
	int r=real_+other.real_;
	int i=imag_+other.imag_;
	return Complex (r,i);
}

Complex operator+(const Complex &c1,const Complex &c2){
	int r=c1.real_+c2.real_;
	int i=c2.imag_+c2.imag_;
	return Complex (r,i);
}