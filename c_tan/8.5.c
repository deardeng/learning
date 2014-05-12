#include<stdio.h>
static int *pointer_1,*pointer_2;
int main()
{
	void swap(int *p1,int *p2);
	int a,b;
	printf("please enter two integer numbers:");
	scanf("%d,%d",&a,&b);
	pointer_1 = &a;
	pointer_2 = &b;
	if(a<b)swap(pointer_1,pointer_2);
	printf("max=%d,min=%d\n",*pointer_1,*pointer_2);
	return 0;
}
void swap(int *pointer_1,int *pointer_2)
{
	int *p=NULL;
	p = pointer_1;
	pointer_1 = pointer_2;
	pointer_2 = p;
}