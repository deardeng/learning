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
    Record key;
    Record *ans;
    int i;
    for(i=0;i<5;i++)
        scanf("%s",array[i].key);
    qsort(array,5,sizeof(Record),r_compare);
    strcpy(key.key,"deng");
    ans=bsearch(&key,array,5,sizeof(Record),r_compare);
    printf("%s\n",((Record *)ans)->key);
    return EXIT_SUCCESS;
}
