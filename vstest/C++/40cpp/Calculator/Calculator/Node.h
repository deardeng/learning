#ifndef _NODE_H_
#define _NODE_H_


class Node
{
public:
	virtual double Calc() const=0;
	virtual ~Node(){}
};

class NumberNode:public Node{
public:
	NumberNode(double number):number_(number){
	}
	double Calc()const;
private:
	const double number_;
};

class BinaryNode:public Node{
public:
	BinaryNode(Node* left,Node* right)
		:left_(left),right_(right){}
	~BinaryNode();
protected:
	Node* const left_;
	Node* const right_;
};

class UnaryNode:public Node{
public:
	UnaryNode(Node* child)
		:child_(child){}
	~UnaryNode();
protected:
	Node* const child_;
};

class AddNode:public BinaryNode{
public:
	AddNode(Node* left,Node* right)
		:BinaryNode(left,right){}
	double Calc() const;
};
class SubNode:public BinaryNode{
public:
	SubNode(Node* left,Node* right)
		:BinaryNode(left,right){}
	double Calc() const;
};
class MultiplyNode:public BinaryNode{
public:
	MultiplyNode(Node* left,Node* right)
		:BinaryNode(left,right){}
	double Calc() const;
};
class DivideNode:public BinaryNode{
public:
	DivideNode(Node* left,Node* right)
		:BinaryNode(left,right){}
	double Calc() const;
};

class UMinusNode:public UnaryNode{
public:
	UMinusNode(Node* child)
		:UnaryNode(child){}
	double Calc()const;
};

#endif //_NODE_H_