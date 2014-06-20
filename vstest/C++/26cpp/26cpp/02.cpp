#include <string>
#include <iostream>
using namespace std;

int main(void){
	string s1("abcdefgd");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.empty() << endl;

	cout << s1.substr(1,2) << endl;
	cout << s1.substr(1,string::npos) << endl;
	string::size_type pos = s1.find('d',1);
	if(pos==string::npos)
		cout << "not found" << endl;
	else
		cout << "pos=" << pos << endl;

	pos = s1.rfind('d',-1);
	if(pos==string::npos)
		cout << "not found" << endl;
	else
		cout << "pos=" << pos << endl;
	return 0;

}