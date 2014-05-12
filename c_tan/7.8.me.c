#include<stdio.h>
void move(char x,char y){
	printf("%c----->%c\n",x,y);
}
void han(int m,char a,char b,char c){
	if(m==1)move(a,b);
	else{
		han(m-1,a,c,b);//a-->b
		move(a,b);
		han(m-1,c,b,a);//b-->c
	}
}
int main()
{
	int m;
	printf("Please input a number.\n");
	scanf("%d",&m);
	han(m,'1','3','2');
	return 0;
}