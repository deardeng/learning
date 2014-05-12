#include<stdio.h>
#include<math.h>

int main(){
	int i,n=100;
	while(n<=200){
		i=2;
		while(i<=sqrt(n)){
			if(n%i==0)
				i=n;
			else
				i++;
		}
		if(i<n)
			printf("n=%d\n",n);
		n++;
	}
	return 0;
}