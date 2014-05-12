#include<stdio.h>
int calculate(int x,int n){
	if(n == 0)
		return 1;
	else if(n == 1)
		return  x;
	else if(n > 1)
		return (2*n-1)*x*calculate(x,(n-1))-(n-1)*calculate(x,(n-2))/n;
}
		
int main()
{
	int x,n;
	printf("input two nums x,n to calculate P(X):");
	scanf("%d,%d",&x,&n);
	printf("\n");
	printf("The result is %d.\n",calculate(x,n));
}