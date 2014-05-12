#include<stdio.h>
#include<string.h>
int is_alpha(char c){
	return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}
int work(char str[]){
	int i,len=0,place,flag=1,lengh=0,point=0;
	for(i = 0;i <= strlen(str);i++)
		if(is_alpha(str[i]))
			if(flag==1)
			{
				point = i;
				flag = 0;
			}
			else{
				len++;
			}
			else{
				flag = 1;
				if(len>=lengh){
					lengh = len;
					place = point;
				}
				len = 0;
			}
	return place;
}
int main(){
	int p,i;
	char string[100];
	printf("Please input a string , I will return its longest word.\n");
	gets(string);
	p=work(string);
	for(i=p;is_alpha(string[i]);i++)
		putchar(string[i]);
	printf("\n");
	return 0;
}