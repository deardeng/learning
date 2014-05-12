#include<stdio.h>
#include<string.h>
int main(){
	char s[10]="hello";
	int i;
	char tmp;
	int len = strlen(s);
	printf("%s,%d\n",s,strlen(s));
	for(i=0;i<len;i++){
		printf("%c\n",s[i]);
	}
	for(i=0;i<len/2;i++){
		tmp = s[i];
		s[i]=s[len-1-i];
		s[len-1-i]=tmp;
	}
	printf("%s\n",s);
	return 0;
}