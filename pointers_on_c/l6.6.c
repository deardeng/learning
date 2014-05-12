#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"l5.4bitarray.h"

#define MAX_VALUE 100000000
#define MAX_BIT_NUMBER ((MAX_VALUE-3)/2)
#define SIZE (MAX_BIT_NUMBER/CHAR_BIT+1)

int main(){
    char sieve[SIZE];
    int number;
    int bit_number;
    char *sp;
    int n_primes;
    int limit;

    for(sp=sieve;sp<&sieve[SIZE];)
        *sp++=0xff;

    for(number=3;number<=MAX_VALUE;number+=2){
        bit_number=(number-3)/2;

        if(!test_bit(sieve,bit_number))
            continue;

        while((bit_number+=number)<=MAX_BIT_NUMBER)
            clear_bit(sieve,bit_number);
    }

    n_primes=1;
    limit=10000000;
    for(bit_number=0,number=3;number<=MAX_VALUE;bit_number+=1,number+=2){
        if(number>limit){
            printf("%d-%d: %d\n",limit - 10000000,limit,n_primes);
            n_primes=0;
            limit += 10000000;
        }
        if(test_bit(sieve,bit_number))
            n_primes+=1;
    }
    printf("%d-%d: %d\n",limit - 10000000,limit,n_primes);
    return EXIT_SUCCESS;
}
