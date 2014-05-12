#include<stdio.h>
#define SIZE 10
struct Student_type{
    char name[10];
    int num;
    int age;
    char addr[15];
}stud[SIZE];

void save(){
    FILE *fp;
    int i;
    if((fp=fopen("stu.dat","wb"))==NULL){
        printf("cannot open file\n");
        return ;
    }
    for(i=0;i<SIZE;i++)
        if(fwrite(&stud[i],sizeof(struct Student_type),1,fp)!=1)
            printf("file write error\n");
    fclose(fp);
}
void load(){
    FILE *fp;
    int i;
    if((fp=fopen("stu_list","rb"))==NULL){
        printf("cannot open infile\n");
        return ;
    }
    for(i=0;i<SIZE;i++)
        if(fread(&stud[i],sizeof(struct Student_type),1,fp)!=1){
            if(feof(fp)){
                fclose(fp);
                return ;
            }
            printf("file read error\n");
        }
    fclose(fp);
}
int main(){
    int i;
    /*printf("Please enter data of students:\n");
    for(i=0;i<SIZE;i++)
        scanf("%s%d%d%s",stud[i].name,&stud[i].num,&stud[i].age,stud[i].addr);*/
    load();
    save();
    return 0;
}
