#include <iostream>
using namespace std;
#include <string>

int main()
{
	string s("hello world");
	s.replace(2,5,"ܽ��");
	s.insert(1,"�Ұ�");
	cout << s << endl;
}

