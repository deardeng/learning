#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define FALSE 0
#define TRUE 1

typedef struct NODE{
    struct NODE *link;
    int value;
}Node;

int sll_insert(Node **linkp,int new_value){
    register Node *current;
    register Node *new;

    while((current=*linkp)!=NULL&&current->value<new_value)
        linkp=&current->link;
    new=(Node *)malloc(sizeof(Node));
    if(new==NULL)
        return FALSE;
    new->value=new_value;

    new->link=current;
    *linkp=new;
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
    sll_insert(&head,18);
    p=head;
    for(;p;p=p->link)
        printf("<%d>",p->value);
    printf("\n");
}
