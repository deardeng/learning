#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char key[10];
    int other_data;
}Record;

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
    qsort(array,5,sizeof(Record),r_compare);
    printf("The qsort 5 segment result!\n");
    for(i=0;i<5;i++){
        printf("%s\n",array[i].key);
    }
    return EXIT_SUCCESS;
}
