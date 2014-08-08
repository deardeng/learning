#include <string.h>
#include <stdio.h>
#include "hash.h"

typedef struct stu{
    char sno[5];
    char name[32];
    int age;
}stu_t;

typedef struct stu2{
    int sno;
    char name[32];
    int age;
}stu2_t;

unsigned int hash_str(unsigned int buckets,void *key){
    char *sno = (char*)key;
    unsigned int index = 0;
    while(*sno){
        index = *sno + 4*index;
        sno++;
    }
    return index % buckets;
}

unsigned int hash_int(unsigned int buckets,void *key){
    int *sno = (int*)key;
    return (*sno) % buckets;
}

int main(void){
    //stu_t stu_arr[] ={
    //    {"1234","AAAA",20},
    //    {"4568","BBBB",23},
    //    {"6729","AAAA",19}
    //};

    //hash_t *hash = hash_alloc(256,hash_str);

    //int size = sizeof(stu_arr) / sizeof(stu_arr[0]);
    //int i;
    //for(i=0;i<size;i++){
    //    hash_add_entry(hash,stu_arr[i].sno,strlen(stu_arr[i].sno),&stu_arr[i],sizeof(stu_arr[i]));
    //}

    //stu_t *s = (stu_t *)hash_lookup_entry(hash,"4568",strlen("4568"));
    //if(s){
    //    printf("%s %s %d\n",s->sno,s->name,s->age);
    //}
    //else{
    //    printf("not Found\n");
    //}

    //hash_free_entry(hash,"1234",strlen("1234"));
    //s = (stu_t *)hash_lookup_entry(hash,"1234",strlen("1234"));
    //if(s){
    //    printf("%s %s %d\n",s->sno,s->name,s->age);
    //}
    //else{
    //    printf("not Found\n");
    //}

    stu2_t stu_arr[] ={
        {1,"AAAA",20},
        {5,"BBBB",23},
        {9,"CCCC",19}
    };

    hash_t *hash = hash_alloc(4,hash_int);
	int size = sizeof(stu_arr) / sizeof(stu_arr[0]);
    int i;
    for(i=0;i<size;i++){
        hash_add_entry(hash,(void *)&stu_arr[i].sno,sizeof(stu_arr[i].sno),&stu_arr[i],sizeof(stu_arr[i]));
    }

    int a = 1;
    stu2_t *s = (stu2_t *)hash_lookup_entry(hash,(void *)&a,sizeof(257));
    if(s){
        printf("%d %s %d\n",s->sno,s->name,s->age);
    }
    else{
        printf("not Found\n");
    }

    a = 1;
    hash_free_entry(hash,(void*)&a,sizeof(258));
    s = (stu2_t *)hash_lookup_entry(hash,(void*)&a,sizeof(259));
    if(s){
        printf("%d %s %d\n",s->sno,s->name,s->age);
    }
    else{
        printf("not Found\n");
    }

    a = 9;
    s = (stu2_t *)hash_lookup_entry(hash,(void*)&a,sizeof(259));
    if(s){
        printf("%d %s %d\n",s->sno,s->name,s->age);
    }
    else{
        printf("not Found\n");
    }
    return 0;
}
