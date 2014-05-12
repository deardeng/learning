#include<stdio.h>
int main()
{
	int a=100,b=10;
	int *pointer_1,*pointer_2;
	pointer_1 = &a;
	pointer_2 = &b;
	printf("a=%d,b=%d\n",a,b);
	printf("*pointer_1=%p,*pointer_2=%p\n",pointer_1,pointer_2);
	
	return 0;
}
