#include<stdio.h>
#include<stdlib.h>

void *rcalloc(int n_elements,size_t element_size){
    char *new_memory;
    n_elements*=element_size;
    new_memory=(char *)malloc(n_elements);
    if(new_memory!=NULL){
        char *ptr;
        ptr=new_memory;
        while(--n_elements>=0)
            *ptr++='\0';
    }
    return new_memory;
}

int main(){
    int *p;
    p=(int *)rcalloc(10,sizeof(int));
}
