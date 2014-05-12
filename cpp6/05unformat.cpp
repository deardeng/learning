#include <iostream>
using namespace std;
//i.get() o.put(), i.getline(), i.ignore(), i.putback(), i.peek()
int main()
{
	int n = cin.get();//int get(), //getchar()
	char c,d,e;
	cin.get(c).get(d).get(e);//istream& get(char& ch)
	cout << n << ',' << c << ',' << d << ',' << e << endl; 
	cout.put(n).put(c).put(d).put(e);
	cin.ignore(200,'\n');
	char ch;
	cin >> ch;//scanf(" %c", &ch);
	cout << "ch=" << ch << endl;
}
