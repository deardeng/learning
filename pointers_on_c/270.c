#include<stdio.h>

void mystery(int n){
    n+=5;
    n/=10;
    printf("%s\n","**********"+10-n);
}

int main(){
    mystery(30);
}
