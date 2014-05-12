#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_OK_RAND (int)(((32767+1)/6)*6-1)
int throw_die(void){
    static int is_seeded=0;
    int value;
    if(!is_seeded){
        is_seeded=1;
        srand((unsigned int)time(NULL));
    }
    do{
        value=rand();
    }while(value>MAX_OK_RAND);
    return value%6+1;
}

int main(){
    int p;
    p=throw_die();
    printf("%d\n",p);
}
