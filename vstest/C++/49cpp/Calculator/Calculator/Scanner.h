#ifndef _SCANNER_H_
#define _SCANNER_H_ 
#include <string>

enum EToken{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
	TOKEN_PLUS,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGH
};

class Scanner
{
public:
	explicit Scanner(const std::string& buf);
	void Accept();
	bool IsEmpty()const;
	bool IsDone()const;
	double Number() const;
	EToken Token()const;
	std::string GetSymbol()const;
private:
	void SkipWhite();
	const std::string buf_;
	unsigned int curPos_;
	EToken token_;
	double number_;
	std::string symbol_;
	bool isEmpty_;
};

#endif //_SCANNER_H_