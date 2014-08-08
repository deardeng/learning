#include <stdio.h>

int *cal(int *input,int n){
    int i;
    int *result = new int[n];
    result[0] = 1;
    for(i=1;i<n;++i){
        result[i] = result[i-1]*input[i-1];
    }
    result[0] = input[n-1];
    for(i=n-2;i>0;--i){
        result[i] *= result[0];
        result[0] *= input[i];
    }
    return result;
}

int main(){
    int a[4] = {2,3,4,5};
    int *p = cal(a,4);
    int i;
    for(i=0;i<4;i++)
        printf("%d ",p[i]);
    return 0;
}
