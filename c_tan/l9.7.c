#include<stdio.h>
struct student{
    long num;
    float score;
    struct student *next;
};
int n;
struct student *del(struct student* head,long num){
    struct student *p1,*p2;
    if(head==NULL){
        printf("\nlist null!\n");
        return head;
    }
    p1=head;
    while(num!=p1->num&&p1->next!=NULL){
        p2=p1;p1=p1->next;
    }
    if(num==p1->num){
        if(p1==head)head=p1->next;
        else p2->next=p1->next;
        printf("delete:%ld\n",num);
        n=n-1;
    }
    else printf("%ld not been found!\n",num);
    return head;
}
