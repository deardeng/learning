#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define FALSE 0
#define TRUE 1

typedef struct NODE{
    struct NODE *link;
    int value;
}Node;

int sll_count_nodes(struct NODE *first){
    int count;
    for(count=0;first;first=first->link)
        count++;
    return count;
}
struct NODE* sll_find(struct NODE *first,int desired_value){
    for(;first;first=first->link)
        if(first->value==desired_value)
            return first;
}

int sll_insert(register Node **linkp,int new_value){
    register Node *current;
    register Node *new;
    while((current=*linkp)&&current->value<new_value)
        linkp=&current->link;
    new=(Node *)malloc(sizeof(Node));
    if(!new)
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

struct NODE* sll_reverse(struct NODE *current){
    struct NODE *previous;
    struct NODE *next;
    for(previous=NULL;current;current=next){
        next=current->link;
        current->link=previous;
        previous=current;
    }
    return previous;
}

int sll_remove(struct NODE **linkp,struct NODE *delete){
    register Node *current;
    assert(delete!=NULL);
    while((current=*linkp)&&current!=delete)
        linkp=&current->link;
    if(current==delete){
        *linkp=current->link;
        free(current);
        return TRUE;
    }
    else
        return FALSE;
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
    printf("The list's count is %d\n",sll_count_nodes(head));
    p=sll_find(head,12);
    printf("%d\n",p->value);
    p=sll_find(head,88);
    if(p)
        printf("%d\n",p->value);
    else
        printf("Not found!\n");
    printf("remove1:%d\n",sll_remove(&head,head->link->link));
    //printf("remove2:%d\n",sll_remove(&head,NULL));
    p=sll_reverse(head);
    for(;p;p=p->link)
        printf("\"%d\"",p->value);
    printf("\n");
}
