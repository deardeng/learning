#include<algorithm>
using std::swap;
void sort(int* a,int n)
{
	if(n<=1)return ;
	if(n==2){
		if(a[1]<a[0])swap(a[1],a[0]);
		return;
	}
	swap(a[n/2],a[0]);
	int jie=a[0];
	int *L = a+1;
	int *R = a+n-1;
	while(L<R){
		while(L<R&&*L<jie)++L;
		while(a<R&&!(*R<jie))--R;
		if(L<R)swap(*L,*R);
	}
	if(*R<jie)swap(*R,a[0]);
	sort(a,R-a);
	sort(R+1,n-1-(R-a));
}