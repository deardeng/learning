#include <iostream>
using namespace std;
#include <string>

int main(void){
	string s1("abcdefghijkl");
	s1.replace(2,2,"AAAAAA");
	cout << s1 << endl;
	s1="abcdefg";
	s1.replace(s1.begin()+1,s1.begin()+4,"AAAAAAA");
	cout << s1 << endl;
	string s2="xyzabc";
	s2.insert(2,"MMMM");
	cout << s2 << endl;
	s2.append("6666");
	cout << s2 << endl;
	string s3="111";
	s2.swap(s3);
	cout << s2 << endl;
	cout << s3 << endl;
	return 0;
}