#include <stdio.h>
#define PASS_MAX 20

void get_pass(char *string){
    int k=0;
    unsigned char ch;
    fflush(stdin);
    while((ch=getchar())!='#'){
        if(k>=PASS_MAX-1||ch=='\b'){
            if(ch=='\b'&&k>0){
                putchar('\b');
                putchar('\0');
                putchar('\b');
                string[--k]='\0';
            }
            continue;
        }
        if(ch<33||ch>122)
            continue;
        putchar('*');
        string[k++]=ch;
    }

}
int main(){
    char string[PASS_MAX];
    get_pass(string);
    printf("%s\n",string);
}
