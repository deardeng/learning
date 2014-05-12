#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define FALSE 0
#define TRUE 1

typedef struct NODE{
    struct NODE *link;
    int value;
}Node;
Node *head1;

int sll_insert(int new_value){
    Node *previous=NULL;
    Node *s=NULL;
    Node *new;
    s=head1;
    while(s->value<new_value){
        previous=s;
        s=s->link;
    }

    new=(Node *)malloc(sizeof(Node));
    if(!new)
        return FALSE;
    new->value=new_value;
    if(head1==s){
        new->link=s;
        //new=head1;
        head1=new;
        return TRUE;
    }

    new->link=s;
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
    Node *p;

    head1=newnode(5);
    head1->link=newnode(10);
    head1->link->link=newnode(15);
    head1->link->link->link=0;
    p=head1;
    for(;p;p=p->link)
        printf("<%d>",p->value);
    printf("\n");
    sll_insert(12);
    p=head1;
    for(;p;p=p->link)
        printf("<%d>",p->value);
    printf("\n");
    sll_insert(3);
    p=head1;
    for(;p;p=p->link)
        printf("<%d>",p->value);
    printf("\n");
}
