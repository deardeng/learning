#include <iostream>
using namespace std;
//结构变量.*成员指针，结构指针->*成员指针
struct date{
	int year;
	int month;
	int day;
	void print(){cout<<year<<'-'<<month<<'-'<<day<<endl;}
};
void f(double d){cout<<d<<endl;}
void showmember(date a[], int n, int date::*p)
{
	for(int i=0; i<n; i++){
		cout << (a+i)->*p << ' ';
	}
	cout << endl;
}
int main()
{
	date a[5]={{2010,8,16},{2010,10,1},{2008,8,8},{2012,12,20},{1999,12,30}};
	date d={1997,7,7};
	cout << "&d=" << &d << endl;
        cout << "--------------------------" << endl;
	cout << "&d.year=" << &d.year << ", &d.month=" << &d.month << ", &d.day=" << &d.day << endl;
        cout << "--------------------------" << endl;
	cout << &date::year << &date::month << &date::day << endl;//类里相对地址
        cout << "--------------------------" << endl;
//	cout << &main << &f << endl;
	union{
		int n;
		int date::*mp;
                int (*p)();
	};
        p=main;
        cout << "main=" << reinterpret_cast<void *>(n) << endl;
        cout << "--------------------------" << endl;
	mp = &date::day;
	cout << "n=" << n << endl;
	cout << d.*mp << endl;
        cout << "--------------------------" << endl;
	mp = &date::year;
	cout << d.*mp << endl;
	showmember(a, 5, &date::month);
	showmember(a, 5, &date::year);
	showmember(a, 5, &date::day);
	d.print();
	a[3].print();
	void (date::*pf)()=&date::print;
	(d.*pf)();
	(a->*pf)();
}

