#include <iostream>
using namespace std;
#include <string>
//io����Ҫ����ת����bool���͡��Դ�������״̬��io����ת��true���Դ��ڴ���״̬��io����ת��false��
//���ڴ���״̬��io����ܾ�ִ��io������.clear()�������״̬
//.eof(),.fail(),.bad(),.good()
int main()
{
	cout << "cin=" << cin << endl;
	cout << cout << endl;
	int n;
	cin >> n;
	cout << "cin=" << cin << endl;
	if(cin) cout << "ƽ������" << endl;
	if(!cin){ cout << "������" << endl; cin.clear(); }
	string s;
	cin >> s;
	cout << "s=[" << s << "]\n";
//	cout << &cin << endl;
//	cout << &cout << endl;
}
