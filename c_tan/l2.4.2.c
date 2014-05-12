#include<stdio.h>

int main()
{
	int a[10];
	int i;
	printf("input 10 num!\n");
	for(i=0;i<10;i++)
	{
		printf("NUM[%d]:",i+1);
		scanf("%d",&a[i]);
	}
	int max=0;
	for(i=0;i<10;i++)
	{
		max = max>a[i]?max:a[i];
	}
	printf("The biggest num is %d\n",max);
}