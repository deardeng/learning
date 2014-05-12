#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct NODE{
    int value;
    struct NODE *link;
}Node;

Node* newnode(int value){
    Node *new;

    new=(Node *)malloc(sizeof(Node));
    assert(new!=0);
    new->value=value;
    return new;
}
int main(){
    Node *head;

    head=newnode(5);
    head->link=newnode(10);
    head->link->link=newnode(15);
    head->link->link->link=0;
    for(;head;head=head->link)
        printf("<%d>",head->value);
    printf("\n");
}