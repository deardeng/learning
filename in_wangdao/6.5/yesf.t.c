#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MOD 3

int main(){
    int a[SIZE];
    int index,count,mod;
    for(index=0;index!=SIZE;index++){
        a[index]=index+1;
    }
    count=SIZE;
    mod=0;
    index=0;
    while(count>1){
        if(a[index]!=0){
            mod++;
            if(mod==MOD){
                a[index]=0;
                mod=0;
                count--;
            }
        }
        index=(index+1)%SIZE;
    }
    for(index=0;index!=SIZE;index++){
        if(a[index]!=0){
            printf("the winner : %d\n",a[index]);
            break;
        }
    }
    return 0;
}
