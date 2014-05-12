#include"10stack.h"
#include<stdio.h>
int main(){
    create_stack(5,10);
    create_stack(2,50);
    int i;
    for(i=0;i<10;i++)
        push(5,i);
    for(i=0;i<50;i++)
        push(2,i);

    // for(i=0;i<5;i++){
    //     printf("%d\n",top());
    //     pop();
    // }
    // putchar('\n');
    for(i=0;i<10;i++){
        printf("%d\n",top(5));
        pop(5);
    }
    putchar('\n');
    for(i=0;i<50;i++){
        printf("%d\n",top(2));
        pop(2);
    }
    putchar('\n');
    return 0;
}
