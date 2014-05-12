#include<stdio.h>
#define false 1
#define true 0

void swap(int*,int*);
void bubblesort(int A[],int len){
	int i,j;
	int flag;
	for(i=0;i<len-1;i++){
		flag = false;
		for(j=len-1;j>i;j--){
			if(A[j]<A[j-1])
				swap(&A[j],&A[j-1]);
			flag = true;
		}
		if(flag == false)return;
	}
}

void swap(int* m,int* n){
	int tmp;
	tmp = *m;
	*m = *n;
	*n = tmp;
}
			
int main(){
	int A[10];
	int i,m;
	printf("Please input 10 numbers\n");
	for(i=0;i<10;i++){
		printf("A[%d]=",i);
		scanf("%d",&A[i]);
	}
	bubblesort(A,10);
	printf("************************\n");
	for(i=0;i<10;i++){
		printf("A[%d]=%d\n",i,A[i]);
	}
}