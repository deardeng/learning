#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int is_not_print(int ch){
    return !isprint(ch);
}

static int (*test_func[])(int)={
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,
    is_not_print
};

#define N_CATEGORIES\
    (sizeof(test_func)/sizeof(test_func[0]))

char *label[]={
    "control",
    "whitespace",
    "digit",
    "lower case",
    "upper case",
    "punctuation",
    "non-printable"
};

int count[N_CATEGORIES];
int total;

int main(){
    int ch;
    int category;

    while((ch=getchar())!=EOF){
        total+=1;
        
        for(category=0;category<N_CATEGORIES;category++)
            if(test_func[category](ch))
                count[category]++;
    }

    if(!total)
        printf("No characters in the input!\n");
    else{
        for(category=0;category<N_CATEGORIES;category++){
            printf("%3.0d/100%scharacters\n",count[category]*100/total,label[category]);
        }
    }
    return EXIT_SUCCESS;
}
