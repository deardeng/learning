#include<stdio.h>
#include<stdlib.h>

struct employee{
    char num[6];
    char name[10];
    char sex[2];
    int age;
    char addr[20];
    int salary;
    char health[8];
    char class[10];
}em[10];
int main(){
    FILE *fp;
    int i;
    printf("input NO.,name,sex,age,addr,salary,health,class\n");
    for(i=0;i<4;i++)
        scanf("%s%s%s%d%s%d%s%s",em[i].num,em[i].name,em[i].sex,&em[i].age,em[i].addr,&em[i].salary,em[i].health,em[i].class);
    if((fp=fopen("employee","w"))==NULL){
        printf("can not open file.");
        exit(0);
    }
    for(i=0;i<4;i++)
        if(fwrite(&em[i],sizeof(struct employee),1,fp)!=1)
            printf("error\n");
    fclose(fp);
    return 0;
}
