/*2矩阵相乘*/
#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    int b[4][2]={1,2,3,4,5,6,7,8};
    int c[3][2];
    memset(c,0,6*sizeof(int));
    int i,j,k;
    //  i*j=i*k+k*j
    for(i=0;i<3;i++)
        for(k=0;k<4;k++)
            for(j=0;j<2;j++)
                c[i][j]+=a[i][k]*b[k][j];
    for(i=0;i<3;i++){
        for(j=0;j<2;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }

    return 0;
}
