#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1024

int a[SIZE];

int main(int argc, const char *argv[])
{
    int count =10;
    srand(time(NULL));
    int i=0,j;
    while(count--){
        a[i++]=rand()/1000;
        printf("%d ",rand()/1000);
    }
    printf("\n");
    int temp;
    printf("=================\n");
    int b[10]={10,9,8,7,6,5,4,3,2,1};
    for(i=0;i<10;i++)
        for(j=0;j<10-1-i;j++)
            if(b[j]>b[j+1]){
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
    for(i=0;i<10;i++)
        printf("%d ",b[i]);
    printf("\n");
    return 0;
}
