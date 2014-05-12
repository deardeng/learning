void sort(int* a,int n)
{
	int j;
	for(int i=1;i<n;i++){
		int t = a[i];
		for(j=i;j>0&&t<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=t;
	}
}