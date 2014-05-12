#include<stdio.h>

void copy_n(char dst[],char src[],int n){
    int dst_index,src_index;
    src_index=0;
    for(dst_index=0;dst_index<n;dst_index+=1){
        dst[dst_index]=src[src_index];
        if(src[src_index]!=0)
            src_index+=1;
    }
}

int main(){
    char s1[100];
    char s2[100]="world";
    copy_n(s1,s2,100);
    printf("%s",s1);
}
