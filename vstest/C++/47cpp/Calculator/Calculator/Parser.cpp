#include "Parser.h"
#include "Scanner.h"
#include "Node.h"
#include <cassert>
#include <iostream>
#include "Calc.h"
Parser::Parser(Scanner& scanner,Calc& calc)
:scanner_(scanner),tree_(0),calc_(calc)
{
}
void Parser::Parse(){
	tree_=Expr();
}

Node* Parser::Expr(){
	Node* node = Term();
	EToken token  = scanner_.Token();
	/*if (token == TOKEN_PLUS)
	{
		scanner_.Accept();
		Node *nodeRight = Expr();
		node = new AddNode(node,nodeRight);

	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.Accept();
		Node *nodeRight = Expr();
		node = new SubNode(node,nodeRight);
	}*/

	if(token == TOKEN_PLUS || token == TOKEN_MINUS){
		//Expr := Term { ('+' | '-') Term }
		MultipleNode* multipleNode = new SumNode(node); 
		do{
			scanner_.Accept();
			Node* nextNode = Term();
			multipleNode->AppendChild(nextNode,(token == TOKEN_PLUS));
			token = scanner_.Token();
		}while(token == TOKEN_PLUS || token == TOKEN_MINUS);
		node = multipleNode;
	}//BNF��ʾ��
	else if(token == TOKEN_ASSIGH){
		//Expr := Term = Expr
		scanner_.Accept();
		Node* nodeRight = Expr();
		if(node->IsLvalue()){
			node = new AssignNode(node,nodeRight);
		}
		else{
			status_ = STATUS_ERROR;
			std::cout << "The left-hand side of an assignment must be a varialbe." << std::endl;
			//Todo �׳��쳣
		}
	}
	return node;
}
Node* Parser::Term(){
	Node* node = Factor();
	EToken token  = scanner_.Token();
	/*if (token == TOKEN_MULTIPLY)
	{
		scanner_.Accept();
		Node *nodeRight = Term();
		node = new MultiplyNode(node,nodeRight);

	}
	else if (token == TOKEN_DIVIDE)
	{
		scanner_.Accept();
		Node *nodeRight = Term();
		node = new DivideNode(node,nodeRight);
	}*/
	if(token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE){
		//Term := Factor { ('*' | '/') Term }
		MultipleNode* multipleNode = new ProductNode(node); 
		do{
			scanner_.Accept();
			Node* nextNode = Factor();
			multipleNode->AppendChild(nextNode,(token == TOKEN_MULTIPLY));
			token = scanner_.Token();
		}while(token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE);
		node = multipleNode;
	}
	return node;
}
Node* Parser::Factor(){
	Node* node= 0;
	EToken token =  scanner_.Token();
	if(token == TOKEN_LPARENTHESIS){
		scanner_.Accept(); //accept '('
		node =  Expr();
		if(scanner_.Token() == TOKEN_RPARENTHESIS){
			scanner_.Accept();//accept ')'
		}
		else{
			status_ = STATUS_ERROR;
			//Todo:�׳��쳣
			std::cout << "missing paraenthsis" << std::endl;
			node = 0;
		}
	}
	else if(token == TOKEN_NUMBER){
		node = new NumberNode(scanner_.Number());
		scanner_.Accept();
	}
	else if(token == TOKEN_IDENTIFIER){
		std::string symbol = scanner_.GetSymbol();
		unsigned int id = calc_.FindSymbol(symbol);
		scanner_.Accept();
		if(id == SymbolTable::IDNOTFOUND){
			id = calc_.AddSymbol(symbol);
		}
		node = new VariableNode(id,calc_.GetStorage());
	}
	else if(token == TOKEN_MINUS){
		scanner_.Accept();//accept minus
		node = new UMinusNode(Factor());
	}
	else{
		status_ = STATUS_ERROR;
		//Todo:�׳��쳣
		std::cout << "Not a valid expression" << std::endl;
		node = 0;
	}
	return node;
}
double Parser::Calculate()const{
	assert(tree_!=0);
	return tree_->Calc();
}
