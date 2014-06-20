#include <iostream>
using namespace std;


//struct Link{
//	int data;
//	struct Link *next;
//};
//struct Stack{
//	struct Link *head;
//	int size;
//};
//void StackInit(struct Stack *stack){
//	stack->head=NULL;
//	stack->size=0;
//}
//void StackPush(struct Stack *stack,const int data){
//	struct Link *node;
//	node = (struct Link*)malloc(sizeof(struct Link));
//	assert(node!=NULL);
//	node->data=data;
//	node->next=stack->head;
//	stack->head=node;
//	++stack->size;
//}
//int StackEmpty(struct Stack *stack){
//	return stack->size==0;
//}
//int StackPop(struct Stack *stack,int *data){
//	if(StackEmpty(stack)){
//		return 0;
//	}
//	struct Link *tmp = stack->head;
//	*data=stack->head->data;
//	stack->head=stack->head->next;
//	free (tmp);
//	--stack->size;
//	return 1;
//}
//void StackCleanup(struct Stack *stack){
//	struct Link *tmp;
//	while(stack->head){
//		tmp=stack->head;
//		stack->head=stack->head->next;
//		free (tmp);
//	}
//	stack->size=0;
//}
//int main(void){
//	struct Stack stack;
//	StackInit(&stack);
//	int i;
//	for(i=0;i<5;i++){
//		StackPush(&stack,i);
//	}
//	while(!StackEmpty(&stack)){
//		StackPop(&stack,&i);
//		printf("%d ",i);
//	}
//	printf("\n");
//	return 0;
//}
//(void*)0

//NULL 0
class Stack{
	struct Link{
		int data_;
		Link *next_;
		Link(int data,Link *next):data_(data),next_(next){}
	};
public:
	Stack():head_(0),size_(0){}
	~Stack(){
		Link *tmp;
		while(head_){
			tmp=head_;
			head_=head_->next_;
			delete (tmp);
		}
		size_=0;
	}
	void Push(const int data){
		Link* node = new Link(data,head_);
		head_=node;
		++size_;
	}
	bool Empty(){
		return (size_==0);
	}
	bool Pop(int& data){
		if(Empty()){
			return false;
		}
		Link *tmp=head_;
		data=head_->data_;
		head_=head_->next_;
		delete tmp;
		--size_;
		return true;
	}
	

private:
	Link *head_;
	int size_;
};
//避免命名冲突
//类型的扩充
//数据封装,能够保护内部的数据不遭受外界破坏
int main(void){
	Stack stack;
	int i;
	for(i=0;i<5;i++){
		stack.Push(i);
	}
	//while(!StackEmpty(&stack)){
	while(!stack.Empty()){
		//StackPop(&stack,&i);
		//printf("%d ",i);
		stack.Pop(i);
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}