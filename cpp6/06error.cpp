#include <iostream>
using namespace std;
#include <string>
//io对象要求能转换成bool类型。对处于正常状态的io对象转成true，对处于错误状态的io对象转成false。
//处于错误状态的io对象拒绝执行io操作，.clear()清除错误状态
//.eof(),.fail(),.bad(),.good()
int main()
{
	cout << "cin=" << cin << endl;
	cout << cout << endl;
	int n;
	cin >> n;
	cout << "cin=" << cin << endl;
	if(cin) cout << "平安无事" << endl;
	if(!cin){ cout << "出错了" << endl; cin.clear(); }
	string s;
	cin >> s;
	cout << "s=[" << s << "]\n";
//	cout << &cin << endl;
//	cout << &cout << endl;
}
