#include "String.h"
#include <cstring>
#include <iostream>
using namespace std;

String::String(char *str)
{
	/*int len = strlen(str) + 1;
	str_=new char[len];
	memset(str_,0,len);
	strcpy(str_,str);*/
	str_=AllocAndCpy(str);
}

String::~String()
{
	delete[] str_;
}

void String::Display(){
	cout << str_ << endl;

}

String::String(const String& other){
	/*int len = strlen(other.str_) + 1;
	str_=new char[len];
	memset(str_,0,len);
	strcpy(str_,other.str_);*/
	str_=AllocAndCpy(other.str_);

}

char* String::AllocAndCpy(char *str){
	int len = strlen(str) + 1;
	char *tmp=new char[len];
	memset(tmp,0,len);
	strcpy(tmp,str);
	return tmp;

}

String& String::operator=(const String& other){
	if(this == &other)
		return *this;
	delete[] str_;
	str_ = AllocAndCpy(other.str_);
	return *this;
}