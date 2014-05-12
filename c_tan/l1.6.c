#include<stdio.h>
void main()
{
    int a,b,c,ma;
    scanf("%d,%d,%d",&a,&b,&c);
    ma=max(a,b,c);
    printf("max_a_b_c=%d\n",ma);
}
int max(int a,int b,int c)
{
    int m=0;
    m = a;
    if(m<b)
        m=b;
    if(m<c)
        m=c;
    return m;
}
