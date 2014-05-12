#include<assert.h>
/*Interface*/
#define GENERIC_STACK_INTERFACE( STACK_TYPE,SUFFIX)             \
    typedef struct{                                             \
        STACK_TYPE *stack;                                      \
        int top_element;                                        \
        int stack_size;                                         \
    }STACK##SUFFIX;                                             \
        void push##SUFFIX(STACK##SUFFIX *stack,STACK_TYPE value);\
        void pop##SUFFIX(STACK##SUFFIX *stack);                 \
        STACK_TYPE top##SUFFIX(STACK##SUFFIX *stack);           \
        int is_empty##SUFFIX(STACK##SUFFIX *stack);             \
        int is_full##SUFFIX(STACK##SUFFIX *stack);              
/*Implementation*/
#define GENERIC_STACK_IMPLEMENTATION(STACK_TYPE,SUFFIX)         \
    void push##SUFFIX(STACK##SUFFIX *stack,STACK_TYPE value){   \
        assert(!is_full##SUFFIX(stack));                        \
        stack->top_element+=1;                                  \
        stack->stack[stack->top_element]=value;                 \
    }                                                           \
    void pop##SUFFIX(STACK##SUFFIX *stack){                     \
        assert(!is_empty##SUFFIX(stack));                       \
        stack->top_element-=1;                                  \
    }                                                           \
    STACK_TYPE top##SUFFIX(STACK##SUFFIX *stack){               \
        assert(!is_empty##SUFFIX(stack));                       \
        return stack->stack[stack->top_element];                \
    }                                                           \
    int is_empty##SUFFIX(STACK##SUFFIX *stack){                 \
        return stack->top_element==-1;                          \
    }                                                           \
    int is_full##SUFFIX(STACK##SUFFIX *stack){                  \
        return stack->top_element==stack->stack_size-1;         \
    }

/*Stacks*/
#define GENERIC_STACK(NAME,STACK_SIZE,STACK_TYPE,SUFFIX)        \
    static STACK_TYPE NAME##stack[STACK_SIZE];                  \
    STACK##SUFFIX NAME={NAME##stack,-1,STACK_SIZE};
