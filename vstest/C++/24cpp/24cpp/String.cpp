#pragma warning(disable:4996)
#include "String.h"
#include <cstring>
//#include <iostream>
//using namespace std;

String::String(const char* str)
{
	str_=AllocAndCpy(str);
}

String::~String()
{
	delete[] str_;
}

String::String(const String& other){
	str_=AllocAndCpy(other.str_);
}
const char& String::operator[](unsigned int index)const{
	return str_[index];
	
}
char& String::operator[](unsigned int index){
	//return str_[index];
	//non const 版本调用 const 版本

	return const_cast<char&>(static_cast<const String&>(*this)[index]);

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
	return Assign(other.str_);
}

bool String::operator !()const{
	return strlen(str_)!=0;
}
void String::Display()const{
	cout << str_ << endl;
}
String& String::operator=(const char* str){
	return Assign(str);
}

String operator+(const String& s1,const String& s2){
	//int len = strlen(s1.str_)+strlen(s2.str_)+1;
	//char* newstr = new char[len];
	//memset(newstr,0,len);
	//strcpy(newstr,s1.str_);
	//strcat(newstr,s2.str_);

	//String tmp = String(newstr);
	//delete newstr;

	String str=s1;
	str+=s2;
	return str;

	//return String(newstr);这样传递回去会导致newstr分配的内存泄漏。
}

String& String::Assign(const char* str){
	delete[] str_;
	str_ = AllocAndCpy(str);
	return *this;
}

String& String::operator+=(const String& other){
	int len = strlen(str_)+strlen(other.str_)+1;
	char* newstr = new char[len];
	memset(newstr,0,len);
	strcpy(newstr,str_);
	strcat(newstr,other.str_);
	delete[] str_;
	str_=newstr;

	return *this;

}

ostream& operator<<(ostream& os,const String& str){
	os << str.str_;
	return os;
}

istream& operator>>(istream& is,String& str){
	char tmp[1024];
	is >> tmp;
	str = tmp;
	return is;
}