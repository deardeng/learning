#include<stdio.h>
struct Student{
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
}student1;
int main(){
    printf("%d\n",sizeof(student1));
    printf("%d\n",sizeof(float));
    return 0;
}
