#include <iostream>
using namespace std;
#include <string>
//i对象.getline(char数组,数组大小);如果不能读完一整行会设置错误状态
//getline(i对象,string对象引用);不是成员函数，而是全局函数
//这两个版本都可以用第三个参数指定读到什么字符为止，默认是'\n'
int main()
{
	char buf[10];
	if(!cin.getline(buf,sizeof(buf))){
		cout << "错误：行超长\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	string s;
	getline(cin, s, '~');
	cout << "buf=[" << buf << "]\n";
	cout << "s=[" << s << "]\n";
	printf("%s\n", s.c_str());
}
