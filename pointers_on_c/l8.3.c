#include<stdio.h>
#define FALSE 0
#define TRUE 1

int identity_matrix(int matrix[3][3]){
    int row;
    int column;

    for(row=0;row<3;row+=1){
        for(column=0;column<3;column+=1){
            if(matrix[row][column]!=(row==column))
                return FALSE;
        }
    }
    return TRUE;
}

int main(){
    int a[3][3]={
        {1,0,0},
        {0,1,0},
        {0,0,2}
    };
    printf("%d\n",identity_matrix(a));
}
