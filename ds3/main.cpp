#include<iostream>
using namespace std;
#include<ctime>
void sort(int* a,int n);

int main()
{
	const int N = 10240;
	int a[N];
	for(int i=0;i<N;i++)
		a[i] = N-i;
	for(int i=0;i<10;i++)
		cout << a[i] << ' ';
	cout << endl;
	clock_t t1 = clock();
	sort(a,N);
	clock_t t2 = clock();
	cout << double(t2-t1)/CLOCKS_PER_SEC << endl;
	for(int i=0;i<10;i++)
		cout << a[i] << ' ';
	cout << endl;
}