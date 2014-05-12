#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *in,*out;
    char ch,infile[10],outfile[10];
    printf("输入读入文件的名字：");
    scanf("%s",infile);
    printf("输入输出文件的名字：");
    scanf("%s",outfile);
    if((in=fopen(infile,"r"))==NULL){
        printf("无法打开此文件\n");
        exit(0);
    }
    if((out=fopen(outfile,"w"))==NULL){
        printf("无法打开此文件\n");
        exit(0);
    }
    while(!feof(in)){
        if((ch=fgetc(in))>=0){
            fputc(ch,out);
            putchar(ch);
        }
    }
    putchar(10);
    fclose(in);
    fclose(out);
}
