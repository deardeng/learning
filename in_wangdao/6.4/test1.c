#include <stdio.h>
int main(int argc, char **argv) {
    int i;
    for(i = 0; i != 10; ++i){
        //if(i % 2 == 1){
        //printf("%d ", i);
        //}

        //考虑continue之后的代码顺序
        if(i % 2 == 0){
            continue;
        }
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
