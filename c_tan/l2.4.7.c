#include<stdio.h>

int main(){
	int m,n,d,r;
	printf("Please input two numbers\n");
	scanf("%d,%d",&m,&n);
	if(m<n){
		d=m;
		m=n;
		n=d;
	}
	while(1){
		r = m%n;
		if(r==0)
			break;
		else{
			m = n;
			n = r;
		}
	}
	printf("n=%d\n",n);
}