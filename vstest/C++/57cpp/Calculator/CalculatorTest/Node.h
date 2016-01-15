#ifndef _NODE_H_
#define _NODE_H_

class Node
{
public:
	Node();
	~Node();
	void Calc()const;
};
class NodePtr{
public:
	explicit NodePtr(Node* ptr=0):ptr_(ptr){}
	NodePtr(NodePtr& other)
		:ptr_(other.Release()){}
	NodePtr& operator=(NodePtr& other){
		Reset(other.Release());
		return *this;
	}
	~NodePtr(){delete ptr_;}
	Node& operator*()const{return *Get();}
	Node* operator->()const{return ptr_;}
	Node* Get()const{return ptr_;}
	Node* Release(){
		Node* tmp = ptr_;
		ptr_ = 0;
		return tmp;
	}
	void Reset(Node* ptr=0){
		if(ptr_!=ptr){
			delete ptr_;
		}
		ptr_ = ptr;
	}

private:
	Node* ptr_;
};
#endif//_NODE_H_