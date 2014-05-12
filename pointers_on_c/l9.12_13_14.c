#include<ctype.h>
#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

int prepare_key(char *key){
    register char *keyp;
    register char *dup;
    register int character;

    if(*key=='\0')
        return FALSE;
    //for(keyp=key;(character=*keyp)!='\0';keyp++){
    //    if(!islower(character)){
    //        if(!isupper(character))
    //            return FALSE;
    //        *keyp=tolower(character);
    //    }
    //}
    for(keyp=key;*keyp!='\0';keyp++){
        if(!islower(*keyp)){
            if(!isupper(*keyp))
                return FALSE;
            *keyp=tolower(*keyp);
        }
    }
    //for(keyp=key;(character=*keyp)!='\0';){
    //    dup=++keyp;
    //    while((dup=strchr(dup,character))!=NULL)
    //        strcpy(dup,dup+1);
    //}
     for(keyp=key;*keyp!='\0';){
         dup=keyp+1;
         while((dup=strchr(dup,*keyp))!=NULL)
             strcpy(dup,dup+1);
         keyp++;
     }
    for(character='a';character<='z';character++){
        if(!strchr(key,character)){
            *keyp++=character;
            *keyp='\0';
        }
    }
    return TRUE;
}
void encrypt(char *data,char const *key){
    register int character;
    for(;(character=*data)!='\0';data++){
        if(islower(character))
            *data=key[character-'a'];
        else if(isupper(character))
            *data=toupper(key[character-'A']);
    }
}
static char alphabet[]="abcdefghijklmnopqrstuvwxyz";

void decrypt(char *data,char const *key){
    register int character;
    for(;(character=*data)!='\0';data++){
        if(islower(character))
            *data=alphabet[strchr(key,character)-key];
        else if(isupper(character))
            *data=toupper(alphabet[strchr(key,tolower(character))-key]);
    }
}
int main(){
    //char data[100]="ATTACK AT DAWN";
    char data[100]="dear DENG!!";
    char key[100]="TRAILBLAZERS";
    printf("%d\n",strlen(alphabet));
    prepare_key(key);
    printf("%s\n",key);
    encrypt(data,key);
    printf("%s\n",data);
    decrypt(data,key);
    printf("%s\n",data);
}
