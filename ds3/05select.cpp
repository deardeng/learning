#include<algorithm>
using std::swap;
void sort(int* a,int n)
{
	for(int i=1;i<n;i++){
		int min=i-1;
		for(int j=i;j<n;j++)
			if(a[j]<a[min])
				min=j;
			swap(a[min],a[i-1]);
	}
}
// {
// 	int k;
// 	for(int i=0;i<n-1;i++){
// 		int min=a[i];
// 		for(int j=i+1;j<n;j++){
// 			if(min>a[j]){min=a[j];k=j;}
// 			swap(a[i],a[k]);
// 		}
// 	}
// }