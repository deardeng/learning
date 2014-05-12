#include<stdlib.h>
#include<stdio.h>

#define SIZE 10

#define TRUE 1
#define FALSE 0

int main(){
    char sieve[SIZE];
    char *sp;
    int number;

    for(sp=sieve;sp<&sieve[SIZE];)
        *sp++=TRUE;

    for(number=3;;number+=2){
        sp=&sieve[0]+(number-3)/2;
        if(sp>=&sieve[SIZE])
            break;
        while(sp+=number,sp<&sieve[SIZE])
            *sp=FALSE;
    }

    printf("2\n");
    for(number=3,sp=&sieve[0];sp<&sieve[SIZE];number+=2,sp++){
        if(*sp)
            printf("%d\n",number);
    }
    return EXIT_SUCCESS;
}
