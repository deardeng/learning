#include<stdio.h>
#include<string.h>

char const *keyword[]={
    "do",
    "for",
    "if",
    "register",
    "return",
    "switch",
    "while",
    NULL
};
#define N_KEYWORD (sizeof(keyword)/ sizeof(keyword[0]))

int lookup_keyword(char const * const desired_word,char const *keyword_table[],int const size){
    char const **kwp;
    //for(kwp=keyword_table;kwp<keyword_table+size;kwp++)
    for(kwp=keyword_table;*kwp!=NULL;kwp++)
        if(strcmp(desired_word,*kwp)==0)
            return kwp-keyword_table;
    return -1;
}
int main(){
   // printf("%d\n",sizeof(keyword));
   // printf("%d\n",sizeof(keyword[0]));
    printf("%d\n",lookup_keyword("for",keyword,N_KEYWORD));
    printf("%d\n",lookup_keyword("if",keyword,N_KEYWORD));
    printf("%d\n",lookup_keyword("fi",keyword,N_KEYWORD));
}
