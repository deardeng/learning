#include<stdio.h>
int main()
{
	void inv(int x[],int n);
	int i,a[11]={3,7,9,11,0,6,7,5,4,2,15};
	printf("The original array:\n");
	for(i=0;i<11;i++)
		printf(" %d",a[i]);
	printf("\n");
	inv(a,11);
	printf("The array has been inverted:\n");
	for(i=0;i<11;i++)
		printf(" %d",a[i]);
	printf("\n");
	return 0;
}

void inv(int x[],int n)
{
	int temp,i,j,m=(n-1)/2;
	for(i=0;i<=m;i++)
	{
		j = n-1-i;
		temp =x[i];x[i]=x[j];x[j]=temp;
	}
	return ;
}