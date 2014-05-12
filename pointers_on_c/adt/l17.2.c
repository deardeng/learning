#include<stdio.h>
#include<assert.h>
#include"queue.h"

static QUEUE_TYPE *queue;
static int queue_size;
static int front=1;
static int rear=0;

void create_queue(size_t size){
    assert(queue_size==0);
    queue_size=size;
    queue=(QUEUE_TYPE *)malloc(queue_size*sizeof(QUEUE_TYPE));
    assert(queue!=NULL);
}

void destroy_queue(void){
    assert(queue_size>0);
    queue_size=0;
    free(queue);
    queue=NULL;
}

void resize_queue(size_t new_size){
    QUEUE_TYPE *old_queue;
    int i;
    int rear_plus_one;

    if(front<=rear)
        i=rear-front+1;
    else 
        i=queue_size-front+rear+1;
    i%=queue_size;
    assert(new_size>=i);
    old_queue=queue;
    queue=(QUEUE_TYPE *)malloc(new_size*sizeof(QUEUE_TYPE));
    assert(queue!=NULL);
    queue_size=new_size;

    i=0;
    rear_plus_one=(rear+1)%queue_size;
    while(front!=rear_plus_one){
        queue[i]=old_queue[front];
        front=(front+1)%queue_size;
        i++;
    }
    front=0;
    rear=(i+queue_size-1)%queue_size;

    free(old_queue);
}

void insert(QUEUE_TYPE value){
    assert(!is_full());
    rear=(rear+1)%queue_size;
    queue[rear]=value;
}

void delete(void){
    assert(!is_empty());
    front=(front+1)%queue_size;
}

QUEUE_TYPE first(void){
    assert(!is_empty());
    return queue[front];
}

int is_empty(void){
    assert(queue_size>0);
    return(rear+1)%queue_size==front;
}

int is_full(void){
    assert(queue_size>0);
    return (rear+2)%queue_size==front;
}

int main(){
    create_queue(5);
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
    resize_queue(11);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    for(i=0;i<10;i++){
        printf("%d\n",first());
        delete();
    }
    putchar('\n');
    destroy_queue();
    return 0;
}
