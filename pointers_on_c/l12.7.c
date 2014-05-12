#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<malloc.h>

#define TRUE 1
#define FALSE 0

typedef struct WORD{
    char *word;
    struct WORD *next;
}Word;

typedef struct LIST{
    char letter;
    struct LIST *next;
    Word *word_list;
}List;

int concordance_insert(List **listp,char *the_word){
    int first_char;
    List *current_list;
    Word *current_word;
    Word **wordp;
    int comparison;
    Word *new_word;

    first_char=*the_word;
    if(!islower(first_char))
        return FALSE;

    while((current_list=*listp)&&current_list->letter<first_char)
        listp=&current_list->next;

    if((!current_list)||current_list->letter>first_char){
        List *new_list;
        new_list=(List *)malloc(sizeof(List));
        if(!new_list)
            return FALSE;
        new_list->letter=first_char;
        new_list->word_list=NULL;
        new_list->next=current_list;
        *listp=new_list;
        current_list=new_list;
    }

    wordp=&current_list->word_list;
    while((current_word=*wordp)){
        comparison=strcmp(current_word->word,the_word);
        if(comparison>=0)
            break;
        wordp=&current_word->next;
    }

    if(current_word&&(!comparison))
        return FALSE;

    new_word=(Word *)malloc(sizeof(Word));

    if(!new_word)
        return FALSE;


    new_word->word=malloc(strlen(the_word)+1);
    if(!new_word->word)
        return FALSE;
    strcpy(new_word->word,the_word);

    new_word->next=current_word;
    *wordp=new_word;
    return TRUE;
}
//sll_insert(register List **linkp,char  new_letter){//构造一个单链表
//    register List *current;
//    register List *new;
//
//    while((current=*linkp)&&current->letter<new_letter)
//        linkp=&current->next;
//
//    new=(List *)malloc(sizeof(List));
//    if(!new)
//        return FALSE;
//    new->letter=new_letter;
//
//    new->next=current;
//    *linkp=new;
//    return TRUE;
//}
void print(List *linkp){
    while(linkp){
        printf("<%c>\n",linkp->letter);
        while(linkp->word_list){
            if(linkp->word_list->next)
                printf("%s-->",linkp->word_list->word);
            else
                printf("%s\n",linkp->word_list->word);
            linkp->word_list=linkp->word_list->next;
        }
        linkp=linkp->next;
    }
    printf("\n");
}

int main(){
    List *apb=NULL;
   //char i;
    char word[100];
   // for(i='a';i<='z';i++)//构造一个单链表,节点内容从a到z
   //     sll_insert(&apb,i);
   // print(apb);
   // concordance_insert(&apb,"abc");
   // concordance_insert(&apb,"ac");
   // concordance_insert(&apb,"dengxin");
   // concordance_insert(&apb,"hello");
   // concordance_insert(&apb,"ello");
   // concordance_insert(&apb,"deardeng");
   // concordance_insert(&apb,"chengzongquan");
   // concordance_insert(&apb,"xiaomi");
   // concordance_insert(&apb,"ac");
    while(gets(word))
        concordance_insert(&apb,word);
    print(apb);
}
