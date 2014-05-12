#include <iostream>
using namespace std;

extern "C" 
void print(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << endl;
}
void print(int a[], int n, char sep)
{
	for(int i=0; i<n; i++)
		cout << a[i] << sep;//(i==n-1?'\n':sep);
	cout << "\b " << endl;
}
void print(int a[], int n, char sep, bool bra)
{
	if(bra) cout << '[';
	if(n>0) cout << *a;
	for(int i=1; i<n; i++)
		cout << sep << a[i];
	if(bra) cout << ']';
	cout << endl;
}
int main()
{
	int a[5]={11,22,33,44,55};
	print(a, 5);		//11 22 33 44 55
	print(a, 5, ',');	//11,22,33,44,55
	print(a, 5, ',', true);	//[11 22 33 44 55]
	print(a, 5, ',', false);	//[11 22 33 44 55]
}

