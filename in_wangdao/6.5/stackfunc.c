#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1024

int main(int argc,char *argv[]){
    char line[LEN];
    char st_arr[LEN];
    int st_top=-1,index,flag;
    while(fflush(stdin),memset(line,0,LEN),memset(st_arr,0,LEN),gets(line)!=NULL){
        flag=0;
        for(index=0;index!=LEN&&!flag;index++){
            switch(line[index]){
                case '(':
                    st_arr[++st_top]=line[index];
                    break;
                case ')':
                    if(st_top==-1){
                        flag=1;
                    }else if(st_arr[st_top]!='('){
                        flag=1;
                    }else{
                        st_top--;
                    }
                    break;
                case '[':
                    st_arr[++st_top]=line[index];
                    break;
                case ']':
                    if(st_top==-1){
                        flag=1;
                    }else if(st_arr[st_top]!='['){
                        flag=1;
                    }else{
                        st_top--;
                    }
                    break;
                case '{':
                    st_arr[++st_top]=line[index];
                    break;
                case '}':
                    if(st_top==-1){
                        flag=1;
                    }else if(st_arr[st_top]!='{'){
                        flag=1;
                    }else{
                        st_top--;
                    }
                    break;
            }
        }
        if(flag||st_top!=-1){
            printf("No!\n");
        }else{
            printf("Yes!\n");
        }
    }
    return 0;
}
