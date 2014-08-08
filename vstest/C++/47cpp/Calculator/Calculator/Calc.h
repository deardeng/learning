#ifndef _CALC_H_
#define _CALC_H_
#include "SymbolTable.h"
#include "Storage.h"
#include <string>
class Parser;
class Calc
{
	friend class Parser;
public:	
	Calc():storage_(symTbl_){}
private:
	Storage& GetStorage(){
		return storage_;
	}
	unsigned int AddSymbol(const std::string& str);
	unsigned int FindSymbol(const std::string& str)const;
	SymbolTable symTbl_;
	Storage storage_;
};

#endif//_CALC_H_