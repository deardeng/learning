#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

int n_cntrl;
int n_space;
int n_digit;
int n_lower;
int n_upper;
int n_punct;
int n_nprint;
int total;

int main(){
    int ch;
    int category;

    while((ch=getchar())!=EOF){
        total+=1;

        if(iscntrl(ch))
            n_cntrl+=1;
        if(isspace(ch))
            n_space+=1;
        if(isdigit(ch))
            n_digit+=1;
        if(islower(ch))
            n_lower+=1;
        if(isupper(ch))
            n_upper+=1;
        if(ispunct(ch))
            n_punct+=1;
        if(!isprint(ch))
            n_nprint+=1;
    }

    if(total==0)
        printf("No characters in the input!\n");
    else{
        printf("\n");
        printf("%3.0f % 100 control characters\n",n_cntrl*100.0/total);
        printf("%3.0f % 100 whitespace characters\n",n_space*100.0/total);
        printf("%3.0f % 100 digit characters\n",n_digit*100.0/total);
        printf("%3.0f % 100 lower case characters\n",n_lower*100.0/total);
        printf("%3.0f % 100 upper case characters\n",n_upper*100.0/total);
        printf("%3.0f % 100 punctuation characters\n",n_punct*100.0/total);
        printf("%3.0f % 100 non-printable characters\n",n_nprint*100.0/total);
    }
    return EXIT_SUCCESS;
}
