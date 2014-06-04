#include <stdio.h>
#define N 10

//插入排序
int main(int argc, char **argv) {

    // 前4个元素是有序的
    int a[N] = { 3, 4, 6, 9, 5, 6, 99, 34, 46, 29 };

    int i;
    int j;
    // i N-1  [1, N-1]

    for(i=0;i<N-2;i++){
        int temp = a[i + 1];
        while (i >= 0 && a[i] > temp) {
            a[i + 1] = a[i];
            --i;
        }
        a[i + 1] = temp;
    }

    for (i = 0; i < N; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
