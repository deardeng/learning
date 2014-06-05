#include <stdio.h>
#include <string.h>
#define N 100
#define M 7
int main(int argc, const char *argv[])
{
    int person[N+1];
    memset(person,-1,(1+N)*sizeof(int));
    int i;
    for(i=1;i<N+1;i++){
        printf("%d ",person[i]);
    }
    putchar('\n');
    int num=N;
    int count=0;
    i=1;
    while(num> 1){
        if(person[i]!=0){
            count++;
            if(count==M){
                person[i]=0;
                count=0;
                num--;
            }
        }
        i=(i+1)%(N+1);
        if(i==0)
            i=1;
    }
    for(i=1;i<N+1;i++){
        if(person[i]!=0)
            printf("The winner is %d \n",i);
    }
    putchar('\n');
    return 0;
}
