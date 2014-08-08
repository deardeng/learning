#include "Scanner.h"
#include <string>
#include <cctype>
#include <stdlib.h>
#include <cstdio>
Scanner::Scanner(const std::string& buf)
:buf_(buf),curPos_(0)
{
	Accept();
	isEmpty_ = (token_==TOKEN_END);
}
bool Scanner::IsDone()const{
	return token_==TOKEN_END;
}
bool Scanner::IsEmpty()const{
	return isEmpty_;
}
double Scanner::Number()const{
	return number_;
}
std::string Scanner::GetSymbol()const{
	return symbol_;
}
EToken Scanner::Token()const{
	return token_;
}
void Scanner::SkipWhite(){
	while(isspace(buf_[curPos_]))
		++curPos_;
}
void Scanner::Accept(){
	SkipWhite();
	switch(buf_[curPos_]){
		case '+':
			token_ = TOKEN_PLUS;
			++curPos_;
			break;
		case '-':
			token_ = TOKEN_MINUS;
			++curPos_;
			break;
		case '*':
			token_ = TOKEN_MULTIPLY;
			++curPos_;
			break;
		case '/':
			token_ =  TOKEN_DIVIDE;
			++curPos_;
			break;
		case '=':
			token_ = TOKEN_ASSIGH;
			++curPos_;
			break;
		case '(':
			token_ = TOKEN_LPARENTHESIS;
			++curPos_;
			break;
		case ')':
			token_ = TOKEN_RPARENTHESIS;
			++curPos_;
			break;
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
		case '.':
			token_ = TOKEN_NUMBER;
			char* p;
			number_=strtod(&buf_[curPos_],&p);
			curPos_=p - &buf_[0];
			break;
		case '\0':case '\n':case '\r':case EOF:
			token_ = TOKEN_END;
			break;
		default:
			if(isalpha(buf_[curPos_])||buf_[curPos_]=='_'){
				token_ = TOKEN_IDENTIFIER;
				symbol_.erase();
				char ch = buf_[curPos_];
				do{
					symbol_ += ch;
					++curPos_;
					ch = buf_[curPos_];
				}while(isalnum(ch)||ch=='_');
			}
			else
				token_ = TOKEN_ERROR;
			break;
	}
}