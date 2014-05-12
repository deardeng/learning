#include<stdio.h>

int main(){
    int number;
    int divisor;

    printf("1\n2\n");

    for(number=3;number<=100;number=number+2){
        for(divisor=3;divisor<number;divisor=divisor+2){
            if(number%divisor==0)
                break;
        }
        if(divisor>=number)
            printf("%d\n",number);
    }
}
