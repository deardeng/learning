#include<algorithm>
using std::swap;
void sort(int* a,int n)
{
	bool changed;
	do{
		changed = false;
		for(int i=1;i<n;i++){
			if(a[i]<a[i-1]){
				swap(a[i],a[i-1]);
				changed = true;
			}
		}
		--n;
	}while(changed);
}