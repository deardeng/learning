#include<stdlib.h>
#define STACK_TYPE int

void create_stack(size_t stack,size_t size);
void push(size_t stack,STACK_TYPE value);
void pop(size_t stack);
STACK_TYPE top(size_t stack);
int is_empty(size_t stack);
int is_full(size_t stack);
