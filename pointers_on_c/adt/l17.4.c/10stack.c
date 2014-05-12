#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include"10stack.h"

#define N_STACK 10

typedef struct{
    STACK_TYPE *stack;
    int size;
    int top_element;
}StackInfo;

StackInfo stacks[N_STACK];

void create_stack(size_t stack,size_t size){
    assert(stack < N_STACK);
    assert(stacks[stack].size==0);
    stacks[stack].size=size;
    stacks[stack].stack=(STACK_TYPE *)malloc(size*sizeof(STACK_TYPE));
    assert(stacks[stack].stack!=NULL);
    stacks[stack].top_element=-1;
}
void destroy_stack(size_t stack){
    assert(stack < N_STACK);
    assert(stacks[stack].size>0);
    stacks[stack].size=0;
    free(stacks[stack].stack);
    stacks[stack].stack=NULL;
}
void push(size_t stack,STACK_TYPE value){
    assert(!is_full(stack));
    stacks[stack].top_element+=1;
    stacks[stack].stack[stacks[stack].top_element]=value;
}
void pop(size_t stack){
    assert(!is_empty(stack));
    stacks[stack].top_element-=1;
}
STACK_TYPE top(size_t stack){
    assert(!is_empty(stack));
    return stacks[stack].stack[stacks[stack].top_element];
}
int is_empty(size_t stack){
    assert(stack<N_STACK);
    assert(stacks[stack].size>0);
    return stacks[stack].top_element==-1;
}
int is_full(size_t stack){
    assert(stack<N_STACK);
    assert(stacks[stack].size>0);
    return stacks[stack].top_element==stacks[stack].size-1;
}
