#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TRUE 1
#define FALSE 0

void shuffle(int *deck,int n_cards){
    int i;
    static int first_time=TRUE;
    if(first_time){
        first_time=FALSE;
        srand((unsigned int)time(NULL));
    }
    for(i=n_cards-1;i>0;i--){
        int where;
        int temp;
        where=rand()%i;
        temp=deck[where];
        deck[where]=deck[i];
        deck[i]=temp;
    }
}

int main(){
    int i,de[100];
    for(i=0;i<100;i++){
        de[i]=i;
    }
    shuffle(de,100);
    for(i=0;i<100;i++){
        printf("%d ",de[i]);
    }
    printf("\n");
}
