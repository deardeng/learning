#include<stdio.h>
#define N 15
int main()
{
	int i,number,top,bott,mid,loca,a[N],flag=1,sign;
	char c;
	printf("enter data:\n");
	scanf("%d",&a[0]);
	i=1;
	while(i<N)
	{
		scanf("%d",&a[i]);
		if(a[i]>=a[i-1])
			i++;
		else
			printf("enter this data again:\n");
	}
	printf("\n");
	for(i=0;i<N;i++)
		printf("%5d",a[i]);
	printf("\n");
	while(flag){
		printf("input number to look for:");
		scanf("%d",&number);
		sign=0;
		top=0;
		bott=N-1;
		if((number<a[0])||(number>a[N-1]))
			loca = -1;
		while((!sign)&&(top<=bott)){
			mid=(bott+top)/2;
			if(number==a[mid])
			{
				loca = mid;
				printf("Has found %d,its position is %d\n",number,loca+1);
				sign = 1;
			}
			else if(number<a[mid])
				bott = mid -1;
			else
				top = mid +1;
		}
		if(!sign||loca == -1)
			printf("cannot find %d.\n",number);
		setbuf(stdin,NULL);
		printf("continue or not(Y/N)?\n");
		scanf("%c",&c);
		if(c=='N'||c=='n')
			flag=0;
	}
	return 0;
}