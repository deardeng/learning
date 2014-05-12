#include <iostream>
using namespace std;

//void JiaoHuan(int a, int b)
//{	int t=a;a=b;b=t; }
void JiaoHuan(int* a, int* b)
{	int t=*a;*a=*b;*b=t; }
void JiaoHuan(int& a, int& b)
{	int t=a;a=b;b=t; }
void print(const int& n)
{	cout << &n << '\t' << hex << showbase << n << endl; }
struct Window{
	string text;
	int x, y;
	int width, height;
};//GUI
void input(Window& r)
{
	cout << "请输入窗口标题、xy坐标、宽度高度:\n";
	cin >> r.text >> r.x >> r.y >> r.width >> r.height;
}
void print(const Window& r)
{
	cout << "=========" << r.text << "========" << endl;
	cout << "从(" << r.x << ',' << r.y << ")到(" << r.x+r.width << ',' << r.y+r.height << ")\n";
}
int main()
{
	Window w;
	input(w);
	print(w);
	int m=10, n=20;
//	JiaoHuan(m,n);
	JiaoHuan(&m,&n);
	cout << m << ',' << n << endl;
	JiaoHuan(m,n);
	cout << m << ',' << n << endl;
	void(*p)(int&,int&) = &JiaoHuan;
	p(m,n);
	cout << m << ',' << n << endl;
	cout << "&m=" << &m << ", &n=" << &n << endl;
	print(m);
	print(n);
	print(123);
	print(m+n);
}

