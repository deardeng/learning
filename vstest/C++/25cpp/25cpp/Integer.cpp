#include "Integer.h"
#include <iostream>
using namespace std;
Integer::Integer(int n):n_(n)
{
}

Integer::~Integer(void)
{
}
void Integer::Display()const{
	cout << n_ << endl;
}

Integer& Integer::operator ++(){
	cout << "Integer& Integer::operator ++()" << endl;
	++n_;
	return *this;
}

Integer::Integer(const Integer& other){
	cout << "copy fun..." << endl;
	n_=other.n_;
	
}

//Integer& operator ++(Integer& i){
//	cout << "Integer& operator ++(Integer& i)" << endl;
//	++i.n_;
//	return i;
//}

Integer Integer::operator++(int i){
	cout << "Integer& Integer::operator ++()" << endl;
	//n_++;
	Integer tmp(n_);
	n_++;
	return tmp;
}

//
//Integer operator++(Integer& i,int n){
//	Integer tmp(i.n_);
//	i.n_++;
//	return tmp;
//}

Integer::operator int(){
	return n_;
}