#include<stdio.h>
#include <stdlib.h>
#define SIZE 100;

int main(int argc,char *argv[]){
    int dim = atoi(argv[1]);//"3", argv[0]
    int a[100][100];
    int circle_num = dim;
    int index_x;
    int left_up, right_down;
    int i, j;
    int number = 0;
    for(index_x = 0; index_x < circle_num; index_x += 2)
    {
        left_up = index_x;
        right_down = circle_num - 1 ;
        //left---->right
        for(i = left_up, j = 0; j <= right_down ; ++j)
            a[i][j] = ++number;
        //right--->left
        for(i = left_up + 1, j = right_down; j >= 0 ; --j)
            a[i][j] = ++number;
    }
    for(i = 0; i < dim; ++i)
    {
        for(j = 0; j < dim; ++j)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
