#include <iostream>
using namespace std;

void print(int a[], int n, char sep=' ', bool bra=false);
int main()
{
	int a[5]={11,22,33,44,55};
	print(a, 5);		//11 22 33 44 55
	print(a, 5, ',');	//11,22,33,44,55
	print(a, 5, ',', false);	//[11 22 33 44 55]
	print(a, 5, ',', true);	//[11 22 33 44 55]
}
void print(int a[], int n, char sep/*=' '*/,bool bra/*=false*/)
{
	if(bra) cout << '[';
	if(n>0) cout << *a;
	for(int i=1; i<n; i++)
		cout << sep << a[i];
	if(bra) cout << ']';
	cout << endl;
}

