#include <iostream>
using namespace std;
//输出缓冲遇到换行、有输入、满、程序结束、flush会刷新
int main()
{
	cout << "Hello";//缓冲，可重定向
	cerr << "World";//无缓冲，不可重定向
	clog << "Tarena";//理论上“缓冲、不可重定向”，实际无缓冲
}
