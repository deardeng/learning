#include"stack.h"
#include<assert.h>
#include<stdio.h>

#define STACK_SIZE 100

static STACK_TYPE stack[STACK_SIZE];
static int top_element=-1;

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
    return top_element==-1;
}

int is_full(void){
    return top_element==STACK_SIZE-1;
}

void resize_stack(size_t new_size){
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
