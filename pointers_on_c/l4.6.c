#include<stdio.h>

int substr(char dst[],char src[],int start,int len){
    int srcindex;
    int dstindex;

    dstindex=0;

    if(start>=0 && len>0){
        for(srcindex=0;srcindex<start&&src[srcindex]!='\0';srcindex+=1);
        while(len>0&&src[srcindex]!='\0'){
            dst[dstindex]=src[srcindex];
            dstindex+=1;
            srcindex+=1;
            len-=1;
        }
    }
    dst[dstindex]='\0';
    return dstindex;
}

int main(){
    char s1[100];
    char s2[100]="hello,who are you ? I am deardeng!";
    int len;
    len=substr(s1,s2,5,10);
    printf("%s\n%d\n",s1,len);
    return 0;
}
