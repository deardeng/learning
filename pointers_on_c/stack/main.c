#include<stdio.h>
#include"tree.h"
#include<stdlib.h>

void print(TREE_TYPE value){
    printf("<%d>",value);
}

int main(){
    int *p;
    insert(1);
    insert(2);
    insert(20);
    insert(22);
    insert(21);
    insert(13);
    insert(18);
    insert(3);
    insert(5);
    pre_order_traverse(print);
    printf("\n");
    p=find(20);
    printf("%p\n",p);
    p=find(100);
    printf("%p\n",p);
    return 0;
}
