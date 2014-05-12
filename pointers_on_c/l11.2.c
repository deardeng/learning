#include<stdio.h>
#include<malloc.h>

#define DELTA 5
static int count;

int* readints(){
    int *array;
    int size;
    int value;

    size=DELTA;
    array=(int *)malloc((size+1)*sizeof(int));
    if(array==NULL)
        return NULL;

    count=0;
    while(scanf("%d",&value)==1){
        count+=1;
        if(count>size){
            size+=DELTA;
            array=(int *)realloc(array,(size+1)*sizeof(int));
            if(array==NULL)
                return NULL;
        }
        array[count]=value;
    }

    if(count<size){
        array=(int *)realloc(array,(count+1)*sizeof(int));
        if(array==NULL)
            return NULL;
    }
    array[0]=count;
    return array;
}

int main(){
    int i,*p;
    int count;
    p=readints();
    for(i=0;i<count;i++)
        printf("%d ",*(p+i));
}
