#include <stdio.h>

#define BUCKETS 101

unsigned int SDBMHash(char *str)
{
    unsigned int hash = 0;
    while (*str)
    {
        // equivalent to: hash = 65599*hash + (*str++);
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
    }
    return (hash & 0x7FFFFFFF) % BUCKETS;
}

int main(void){
	char *keywords[] =
	{
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
	};

    int count[BUCKETS];

    int i;
    for(i=0;i<BUCKETS;i++){
        count[i] = 0;
    }
    int size = sizeof(keywords) / sizeof(keywords[0]);

    for(i=0;i<size;i++){
        unsigned int pos = SDBMHash(keywords[i]);
        count[pos]++;
    }

    for(i=0;i<size;i++){
        int pos = SDBMHash(keywords[i]);
        printf("%-10s: %03d %d\n",keywords[i],pos,count[pos]);
    }
    return 0;
}
