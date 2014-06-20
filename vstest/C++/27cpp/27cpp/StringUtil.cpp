#include "StringUtil.h"

void StringUtil::LTrim(string& s){
	string drop = " \t";
	s.erase(0,s.find_first_not_of(drop));
	
}
void StringUtil::RTrim(string& s){
	string drop = " \t";
	s.erase(s.find_last_not_of(drop)+1,string::npos);
}
void StringUtil::Trim(string& s){
	LTrim(s);
	RTrim(s);
}