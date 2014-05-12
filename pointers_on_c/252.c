#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    struct NODE *fwd;
    struct NODE *bwd;
    int value;
}Node;

int dll_insert(Node *rootp,int value){
    Node *this;
    Node *next;
    Node *newnode;

    for(this=rootp;(next=this->fwd)!=NULL;this=next){
        if(next->value==value)
            return 0;
        if(next->value>value)
            break;
    }
    newnode=(Node *)malloc(sizeof(Node));
    if(newnode==NULL)
        return -1;
    newnode->value =value;

    newnode->fwd=next;
    this->fwd=newnode;
    if(this!=rootp)
        newnode->bwd=this;
    else
        newnode->bwd=NULL;
    if(next!=NULL)
        next->bwd=newnode;
    else
        rootp->bwd=newnode;

    return 1;
}

int main(){
    Node *root,*p=NULL;
    root=malloc(sizeof(Node));
    root->bwd=NULL;
    root->fwd=NULL;
    root->value=0;
    dll_insert(root,1);
    dll_insert(root,2);
    dll_insert(root,3);
    dll_insert(root,8);
    dll_insert(root,9);
    for(p=root;p;p=p->fwd)
        printf("<%d>",p->value);
    printf("\n");
    for(p=root;p;p=p->bwd)
        printf("<%d>",p->value);
    printf("\n");
}
