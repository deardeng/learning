#ifndef _PARSER_H_
#define _PARSER_H_
class Scanner;
class Parser
{
public:
	Parser(Scanner& scanner);
	void Parse();
	double Calculate()const;
private:
	Scanner& scanner_;
};

#endif//_PARSER_H_