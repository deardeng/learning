#include<stdio.h>

int main(){
	int i,sum=0,n=1;
	for(i=0;i<100;i++){
		sum+=n;
		n++;
	}
	printf("The sum is %d.\n",sum);
	return 0;
}