#include<stdio.h>

int main(){
	int num,flag=0;
	printf("Please input a num !\n");
	scanf("%d",&num);
	if(num%3!=0)
		flag =- 1;
	if(flag == 0 && num%5!=0)
		flag =- 1;
	if(flag == 0)
		printf("The num can be div by 3 and 5.\n");
	else
		printf("The num can not be div by 3 and 5.\n");
	return 0;
}