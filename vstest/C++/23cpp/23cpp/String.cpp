#pragma warning(disable:4996)
#include "String.h"
#include <cstring>
#include <iostream>
using namespace std;

String::String(const char* str)
{
	str_=AllocAndCpy(str);
}

String::~String(void)
{
	delete[] str_;
}

String::String(const String& other){
	str_=AllocAndCpy(other.str_);
}

char* String::AllocAndCpy(const char* str){
	int len = strlen(str)+1;
	char* newstr=new char[len];
	memset(newstr,0,len);
	strcpy(newstr,str);

	return newstr;
}

String& String::operator=(const String& other){
	if(this==&other)
		return *this;
	delete[] str_;
	str_=AllocAndCpy(other.str_);
	return *this;
}

bool String::operator !()const{
	return strlen(str_)!=0;
}
void String::Display()const{
	cout << str_ << endl;
}
String& String::operator=(const char* str){
	delete[] str_;
	str_=AllocAndCpy(str);
	return *this;
}