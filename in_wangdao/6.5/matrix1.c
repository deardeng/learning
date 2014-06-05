/*
   before change:
   1  2  3  4
   5  6  7  8
   9 10 11 12
   13 14 15 16
   after change:
   1  2  3  4
   8  7  6  5
   9 10 11 12
   16 15 14 13
*/
#include <stdio.h>

#define N 4
int main(int argc, const char *argv[])
{
    int i,j;
    int a[N][N];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            scanf("%d",&a[i][j]);
    }

    printf("before change:\n");
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%2d ",a[i][j]);
        printf("\n");
    }
    printf("after change:\n");
    int temp,k,l,flag_havedone=0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i%2==1&&!flag_havedone){
                k=0,l=N-1;
                while(k<l){
                    temp=a[i][k];
                    a[i][k]=a[i][l];
                    a[i][l]=temp;
                    k++;
                    l--;
                }
                flag_havedone=1;
            }
            printf("%2d ",a[i][j]);
        }
        printf("\n");
        flag_havedone=0;
    }
    return 0;
}
