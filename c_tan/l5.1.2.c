#include<stdio.h>
int main()
{
    int i,j,n=1;
    for(i=1;i<=4;i++)
    {
            if(n%5==0)printf("\n");
        for(j=1;j<=5;j++,n++)
        {
        //    if(i==3&&j==1)break;
            printf("%d\t",i*j);
        }
        n=0;
    }
    printf("\n");
    return 0;
}
