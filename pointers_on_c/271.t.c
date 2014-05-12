#include<stdio.h>

void dec_to_bin(int value){
    int quotient;

    quotient=value/2;
    if(quotient)
        dec_to_bin(quotient);
    putchar(value%2+'0');
}
int main(){
    int n;
    printf("please input some numbers\n");
    do{
        scanf("%d",&n);
        dec_to_bin(n);
        printf("\n");
    }while(1);
}
