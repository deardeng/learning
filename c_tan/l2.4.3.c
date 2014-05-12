#include<stdio.h>

void swap(int* m ,int* n)
{
	int d;
	d = *m;
	*m = *n;
	*n = d;
}

int main()
{
	int a,b,c;
	printf("input the number of a,b,c.\n");
	scanf("%d,%d,%d",&a,&b,&c);
	if(a<b)
		swap(&a,&b);
	if(a<c)
		printf("max=%d,mid=%d,min=%d\n",c,a,b);
	else{
		if(c>b)
			printf("max=%d,mid=%d,min=%d\n",a,c,b);
		else
			printf("max=%d,mid=%d,min=%d\n",a,b,c);
	}
	return 0;
}