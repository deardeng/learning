#include <cassert>
#include <iostream>
#include <cstring>
#include "Calc.h"
#include "DebugNew.h"
#include "Parser.h"
#include "Scanner.h"
#include "Node.h"
#include "Exception.h"
Parser::Parser(Scanner& scanner,Calc& calc)
:scanner_(scanner),tree_(0),calc_(calc),status_(STATUS_OK)
{
}
Parser::~Parser(){
	delete tree_;
}
STATUS Parser::Parse(){
	tree_=Expr();
	if(!scanner_.IsDone()){
		status_ = STATUS_ERROR;
	}
	return status_;
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
	}//BNF表示法
	else if(token == TOKEN_ASSIGH){
		//Expr := Term = Expr
		scanner_.Accept();
		Node* nodeRight = Expr();
		if(node->IsLvalue()){
			node = new AssignNode(node,nodeRight);
		}
		else{
			status_ = STATUS_ERROR;
			//std::cout << "The left-hand side of an assignment must be a varialbe." << std::endl;
			//Todo 抛出异常
			throw SyntaxError("The left-hand side of an assignment must be a varialbe.");
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
			//Todo:抛出异常
			//std::cout << "missing paraenthsis" << std::endl;
			throw SyntaxError("missing paraenthsis");
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
		if(scanner_.Token() == TOKEN_LPARENTHESIS){//function call
			scanner_.Accept();//accept '('
			node = Expr();
			if(scanner_.Token() == TOKEN_RPARENTHESIS){
				scanner_.Accept();//accept ')'
				if(id != SymbolTable::IDNOTFOUND && calc_.IsFunction(id)){
					node = new FunctionNode(node,calc_.GetFunction(id));
				}
				else{
					status_ = STATUS_ERROR;
					//std::cout << "Unknown function " << "\"" << symbol << "\"" << std::endl;
					char buf[256]={0};
					sprintf(buf,"Unknown function \"%s\".",symbol.c_str());
					throw SyntaxError(buf);
				}
			}
			else{
				status_ = STATUS_ERROR;
				//std::cout << "Missing parenthesis in a function call" << std::endl;
				throw SyntaxError("Missing parenthesis in a function call.");
			}

		}
		else{
			if(id == SymbolTable::IDNOTFOUND){
				id = calc_.AddSymbol(symbol);
			}
			node = new VariableNode(id,calc_.GetStorage());
		}
		
	}
	else if(token == TOKEN_MINUS){
		scanner_.Accept();//accept minus
		node = new UMinusNode(Factor());
	}
	else{
		status_ = STATUS_ERROR;
		//Todo:抛出异常
		//std::cout << "Not a valid expression" << std::endl;
		throw SyntaxError("Not a valid expression.");
		node = 0;
	}
	return node;
}
double Parser::Calculate()const{
	assert(tree_!=0);
	return tree_->Calc();
}
