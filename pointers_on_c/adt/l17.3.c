#include<stdio.h>
#include<assert.h>
#include"queue.h"

typedef struct QUEUE_NODE{
    QUEUE_TYPE value;
    struct QUEUE_NODE *next;
}QueueNode;

static QueueNode *front;
static QueueNode *rear;

void destroy_queue(void){
    while(!is_empty())
        delete();
}

void insert(QUEUE_TYPE value){
    QueueNode *new_node;

    new_node=(QueueNode *)malloc(sizeof(QueueNode));
    assert(new_node!=NULL);
    new_node->value=value;
    new_node->next=NULL;

    if(rear==NULL){
        front=new_node;
    }
    else 
        rear->next=new_node;
    rear=new_node;
}

void delete(void){
    QueueNode *next_node;

    assert(!is_empty());
    next_node=front->next;
    free(front);
    front=next_node;
    if(front==NULL)
        rear=NULL;
}

QUEUE_TYPE first(void){
    assert(!is_empty());
    return front->value;
}

int is_empty(void){
    return front==NULL;
}

int is_full(void){
    return 0;
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    int i;
    //for(i=0;i<4;i++){
    //    printf("%d\n",first());
    //    delete();
    //}
    //putchar('\n');
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    insert(11);
    insert(12);
    insert(13);
    insert(14);
    insert(15);
    insert(16);
    for(i=0;i<16;i++){
        printf("%d\n",first());
        delete();
    }
    putchar('\n');
    destroy_queue();
    return 0;
}
