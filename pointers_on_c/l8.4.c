#include<stdio.h>
#define FALSE 0
#define TRUE 1

int identity_matrix(int *matrix,int size){
    int row;
    int column;

    for(row=0;row<size;row+=1){
        for(column=0;column<size;column+=1){
            if(*matrix++!=(row==column))
                return FALSE;
        }
    }
    return TRUE;
}

int main(){
    int a[3][3]={
        {1,0,0},
        {0,1,0},
        {1,2,3}
    };
    printf("%d\n",identity_matrix(*a,3));
}
