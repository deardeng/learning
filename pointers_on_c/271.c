#include<stdio.h>

void binary_to_ascii(unsigned int value){
    unsigned int quotient;

    quotient=value/10;
    if(quotient)
        binary_to_ascii(quotient);
    putchar(value%10+'0');
    putchar(10);
}

int main(){
    int n;
    printf("please input some numbers\n");
    do{
        scanf("%d",&n);
        binary_to_ascii(n);
    }while(1);
}
