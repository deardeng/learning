#include<stdio.h>
int main(){
	char string[100];
	int i,num=0,flag=0;
	fgets(string,100,stdin);
	for(i=0;(string[i]!='\0');i++)
		if(string[i]==' ')flag=0;
		else if(flag==0){
			num++;
			flag=1;
		}
	printf("The line has %d words\n",num);
	return 0;
}