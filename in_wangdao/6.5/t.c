#include <stdio.h>
#define N 4

int main()
{
    while(1)
    {
        int length,i,num=1,row=0,col=0;
        int matrix[N+1][N+1]={0};
        printf("Please input a number in 1-%d: ",N);
        scanf("%d",&length);
        for(i=0;i<length/2;i++)
        {
            for (;length-1-i>col;col++)
                matrix[row][col]=num++;
            for (;length-1-i>row;row++)
                matrix[row][col]=num++;
            for (;col>i;col--)
                matrix[row][col]=num++;
            for (;row>i;row--)
                matrix[row][col]=num++;
            row++;col++;
        }
        if(length%2==1)
            matrix[row][col]=num++;
        for(row=0;row<length;row++)
        {
            for(col=0;col<length;col++)
                printf("%d ",matrix[row][col]); //3d!
            printf("\n");
        }
    }
    return 0;
}
