#include<stdio.h>
int main(){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
            if(j==i+4||j==-i+4||j==-i+12||j==i-4)
                putchar('*');
            else
                putchar(' ');
        putchar('\n');
    }
}
