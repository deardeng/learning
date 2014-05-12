#include<stdio.h>
void fun(int v){
    while(v/10!=0){
        fun(v%10);
        v=v/10;
    }
    printf("%d ",v);

}
void main()
{
    int n=123;
    fun(n);
}
