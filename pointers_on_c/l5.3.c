#include<stdio.h>

unsigned int reverse_bits(unsigned int value){
    unsigned int answer;
    unsigned int i;
    answer=0;

    for(i=1;i!=0;i<<=1){
        answer<<=1;
        if(value & 1)
            answer|=1;
        value>>=1;
    }
    return answer;
}

int main(){
    int a;
    scanf("%d",&a);
    printf("%u",reverse_bits(a));
    return 0;
}
