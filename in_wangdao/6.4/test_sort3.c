#include <stdio.h>
#define N 10

//插入排序
int main(int argc, char **argv) {

    // 前4个元素是有序的
    int a[N] = { 3, 4, 6, 9, 5, 6, 99, 34, 46, 29 };

    int i;
    int j;
    // i N-1  [1, N-1]

    for(i=1;i<N;i++){
        int t=a[i];
        for(j=i;j>0&&t<a[j-1];j--)
            a[j]=a[j-1];
        a[j]=t;
    }

    for (i = 0; i < N; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
