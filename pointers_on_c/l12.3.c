#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    struct NODE *fwd;
    struct NODE *bwd;
    int value;
}Node;

int dll_insert(Node **frontp,Node **rearp,int value){
    register Node **fwdp;
    register Node *next;
    register Node *newnode;

    fwdp=frontp;
    while(next=*fwdp){
        if(next->value==value)
            return 0;
        if(next->value>value)
            break;
        fwdp=&next->fwd;
    }
    newnode=(Node *)malloc(sizeof(Node));
    if(!newnode)
        return -1;
    newnode->value=value;

    newnode->fwd=next;
    *fwdp=newnode;

    if(fwdp!=frontp)
        if(next!=NULL)
            newnode->bwd=next->bwd;
        else
            newnode->bwd=*rearp;
    else
        newnode->bwd=NULL;
    if(next)
        next->bwd=newnode;
    else
        *rearp=newnode;
    return 1;
}

int main(){
    Node *root,*p=NULL;
    root=malloc(sizeof(Node));
    root->bwd=NULL;
    root->fwd=NULL;
    root->value=0;
    dll_insert(&root->fwd,&root->bwd,1);
    dll_insert(&root->fwd,&root->bwd,3);
    dll_insert(&root->fwd,&root->bwd,5);
    dll_insert(&root->fwd,&root->bwd,7);
    dll_insert(&root->fwd,&root->bwd,8);
    dll_insert(&root->fwd,&root->bwd,9);
    for(p=root;p;p=p->fwd)
        printf("<%d>",p->value);
    printf("\n");
    for(p=root;p;p=p->bwd)
        printf("<%d>",p->value);
    printf("\n");
}
