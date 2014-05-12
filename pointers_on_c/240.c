#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define FALSE 0
#define TRUE 1

typedef struct NODE{
    struct NODE *link;
    int value;
}Node;

int sll_insert(Node **rootp,int new_value){
    Node *current;
    Node *previous;
    Node *new;

    current=*rootp;
    previous=NULL;

    while(current!=NULL&&current->value<new_value){
        previous=current;
        current=current->link;
    }
    new=(Node *)malloc(sizeof(Node));
    if(new==NULL)
        return FALSE;
    new->value=new_value;

    new->link=current;
    if(previous==NULL)
        *rootp=new;
    else
        previous->link=new;
    return TRUE;
}
Node* newnode(int value){
    Node *new;

    new=(Node *)malloc(sizeof(Node));
    assert(new!=0);
    new->value=value;
    return new;
}

int main(){
    Node *head,*p;

    head=newnode(5);
    head->link=newnode(10);
    head->link->link=newnode(15);
    head->link->link->link=0;
    p=head;
    for(;p;p=p->link)
        printf("<%d>",p->value);
    printf("\n");
    sll_insert(&head,12);
    p=head;
    for(;p;p=p->link)
        printf("<%d>",p->value);
    printf("\n");
    sll_insert(&head,3);
    p=head;
    for(;p;p=p->link)
        printf("<%d>",p->value);
    printf("\n");
}
