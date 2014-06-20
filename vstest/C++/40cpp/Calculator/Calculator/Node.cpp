#include "Node.h"
#include <cmath>
#include <iostream>

double NumberNode::Calc() const{
	return number_;
}
BinaryNode::~BinaryNode(){
	delete left_;
	delete right_;
}
UnaryNode::~UnaryNode(){
	delete child_;
}
double AddNode::Calc() const{
	return left_->Calc() + right_->Calc();
}
double SubNode::Calc() const{
	return left_->Calc() - right_->Calc();
}
double MultiplyNode::Calc() const{
	return left_->Calc() * right_->Calc();
}
double DivideNode::Calc() const{
	double divisor = right_->Calc();
	if(divisor!=0.0)
		return left_->Calc() / divisor;
	else{
		std::cout << "Error:Divisor by Zero" << std::endl;
		return  HUGE_VAL;
	}

}

double UMinusNode::Calc()const{
	return -child_->Calc();
}