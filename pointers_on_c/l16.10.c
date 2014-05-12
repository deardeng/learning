#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char key[10];
    int other_data;
}Record;

void insertion_sort(void *base,int n_elements,int el_size,int (*compare)(void const *x,void const *y)){
    char *array;
    char *temp;
    int i;
    int next_element;

    array=base;
    temp=malloc(el_size);
    assert(temp!=NULL);

    for(next_element=1;next_element<n_elements;next_element++){
        char *i_ptr=array;
        char *next_ptr=array+next_element*el_size;

        for(i=0;i<next_element;i++,i_ptr+=el_size)
            if(compare(next_ptr,i_ptr)<0)
                break;

        if(i==next_element)
            continue;

        memcpy(temp,next_ptr,el_size);
        memmove(i_ptr+el_size,i_ptr,(next_element-i)*el_size);

        memcpy(i_ptr,temp,el_size);
    }
    free(temp);
}
int r_compare(void const *a,void const *b){
        return strcmp(((Record *)a)->key,((Record *)b)->key);
}


int main(){
    Record array[5];
    int i;
    printf("Input 5 segment\n");
    for(i=0;i<5;i++){
        scanf("%s",array[i].key);
    }
    insertion_sort(array,5,sizeof(Record),r_compare);
    printf("The qsort 5 segment result!\n");
    for(i=0;i<5;i++){
        printf("%s\n",array[i].key);
    }
    return EXIT_SUCCESS;
}

