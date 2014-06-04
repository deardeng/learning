#include <stdio.h>
#define N 10

int main(int argc, char **argv) {

    int a[N] = { 9, 3, 5, 6, 2, 6, 99, 34, 46, 29 };

    //3 5 6 2 6 9 34 46 29 99
    int i;
    for (i = 0; i < N - 1; ++i) {
        if (a[i] > a[i + 1]) {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }

    for (i = 0; i < N; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i = 0; i < N - 2; ++i) {
        if (a[i] > a[i + 1]) {
            int temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }

    for (i = 0; i < N; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int j;
    for(i=0;i<N-1;i++)
        for(j=0;j<N-i-0;j++)
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    for (i = 0; i < N; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
