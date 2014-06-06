#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
int a[SIZE][SIZE];
int main(int argc, char* argv[])
{

    //int dim = atoi(argv[1]);//"3", argv[0]
    //int circle_num = dim % 2 ? dim / 2 + 1 : dim     / 2;
    //int index_x;
    //int left_up, right_down;
    //int i, j;
    //int number = 0;
    //for(index_x = 0; index_x < circle_num; ++index_x)
    //{
    //    left_up = index_x;
    //    right_down = dim - index_x - 1;
    //    //left---->right
    //    for(i = left_up, j = left_up; j <= right_down ; ++j)
    //        a[i][j] = ++number;
    //    //up--->down
    //    for(i = left_up + 1, j = right_down ; i <=              right_down ; ++i)
    //        a[i][j] = ++number;
    //    //right---left
    //    for(i =                          right_down , j = right_down - 1 ; j >= left_up ; --j)
    //        a[i][j] = ++number;
    //    //down----up
    //    for(i = right_down - 1, j = left_up ; i >= left_up + 1; --i)
    //        a[i][j] = ++number;
    //}
    //for(i = 0; i < dim; ++i)
    //{
    //    for(j = 0; j < dim; ++j)
    //    {
    //        printf("%d\t", a[i][j]);
    //    }
    //    printf("\n");
    //}


    int dim = atoi(argv[1]);//"3", argv[0]
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

    /*int dim = atoi(argv[0]);
      int circle_num = dim;
      int index_x;
      int left_up, right_down;
      int i, j;
      int number = 0;*/


    //system("pause");
    return 0;
}

