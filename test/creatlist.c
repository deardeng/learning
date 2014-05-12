#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node,*Linklist;

void R_Print(Linklist L){
	if(L->next != NULL){
		R_Print(L->next);
	}
	printf("%d\t",L->data);
}

int main(){
	Node* s;
	int x;
	Linklist L;
	L = (Linklist)malloc(sizeof(Node));
	L->next = NULL;
	printf("input some numbers,if input -1000,will back!\n");
	scanf("%d",&x);
	while(x!=-1000){
		s = (Node*)malloc(sizeof(Node));
		s->data = x;
		s->next = L->next;
		L->next =s;
		scanf("%d",&x);
	}
	s = L->next;
	printf("The inputed numbers are:\n");
	while(s!=NULL){
		printf("%d\t",s->data);
		s=s->next;
	}
	printf("\n");
	printf("*****************************\n");
	printf("The overturned numbers are:\n");
	printf("*****************************\n");
	R_Print(L->next);
	printf("\n");
	while(L){
		s=L;
		free(L);
		L = s->next;
	}
		
	return 0;
}