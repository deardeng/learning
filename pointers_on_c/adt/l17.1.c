#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<stddef.h>

static STACK_TYPE *stack;
static int stack_size;
static int top_element=-1;

void create_stack(size_t size){
    assert(stack_size==0);
    stack_size=size;
    stack=malloc(stack_size*sizeof(STACK_TYPE));
    assert(stack!=NULL);
}
void destroy_stack(void){
    assert(stack_size>0);
    stack_size=0;
    free(stack);
    stack=NULL;
}
void push(STACK_TYPE value){
    assert(!is_full());
    top_element+=1;
    stack[top_element]=value;
}
void pop(void){
    assert(!is_empty());
    top_element-=1;
}
STACK_TYPE top(void){
    assert(!is_empty());
    return stack[top_element];
}
int is_empty(void){
    assert(stack_size>0);
    return top_element==-1;
}
int is_full(void){
    assert(stack_size>0);
    return top_element==stack_size-1;
}

void resize_stack(int new_size){
    STACK_TYPE *old_stack;
    int i;

    assert(new_size>top_element);
    old_stack=stack;
    stack=(STACK_TYPE *)malloc(new_size*sizeof(STACK_TYPE));
    assert(stack!=NULL);
    stack_size=new_size;

    for(i=0;i<=top_element;i+=1)
        stack[i]=old_stack[i];
    free(old_stack);
}


int main(){
    create_stack(5);
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    int i;
   // for(i=0;i<5;i++){
   //     printf("%d\n",top());
   //     pop();
   // }
   // putchar('\n');
    resize_stack(10);
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);
    for(i=0;i<10;i++){
        printf("%d\n",top());
        pop();
    }
    putchar('\n');
    return 0;
}
