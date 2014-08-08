#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

double Divide(double a,double b){
	if(b==0.0){
		longjmp(buf,1);		//throw
	}
	else
		return a/b;
}
int main(void){
	int ret;
	ret = setjmp(buf);
	if(ret == 0){			//try
		printf("division...\n");
		printf("%f\n",Divide(5.0,0.0));
	}
	else if(ret==1){		//catch
		printf("division by zero\n");
	}
	return 0;
}