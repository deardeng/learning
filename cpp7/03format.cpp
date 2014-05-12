#include <iostream>
using namespace std;
#include <iomanip>
int main()
{
	cout.width(10);
	cout << 123 << ',' << 123 << endl;
	cout.width(2);
	cout << 123 << ',' << hex << 123 << endl;
	cout << setw(10) << 123 << ',' << dec << 123 << endl;
	cout.setf(ios::hex,ios::basefield);//oct,dec,showbase
	cout << showbase << 123 << endl;
	cout.unsetf(ios::hex);
	cout << 123 << endl;
	cout << 95.0 << endl;
	cout << showpoint << 95.0 << endl;
	cout << scientific << 95.0 << endl;
	cout.precision(3);
	cout << 95.0 << endl;
	cout.unsetf(ios::scientific);
	cout << 95.0 << endl;
	cout << fixed << 95.0 << endl;
	cout << setprecision(2) << 8000.0 << endl;
	cout << showpos << 123 << ',' << 45.6 << endl;
	cout << uppercase << hex << 123 << ',' << scientific << 95.0 << endl;
	cout.fill('#');
	cout << dec << setw(10) << 123 << endl;
	cout << setfill('*') << left << setw(10) << 123 << endl;
	cout << setfill(' ')<<internal << setw(10) << 123 << endl;
	cout << right << setw(10) << "hello" << endl;
	cout << unitbuf << "hello";
	cerr << "world";
}
