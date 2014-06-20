#include <iostream>
using namespace std;
#include "Parser.h"
#include "Scanner.h"
#include <string>
#include "Calc.h"
int main(void){
	Calc calc;
	STATUS status = STATUS_OK;
	do{
		cout << "> ";
		string buf;
		getline(cin,buf);
		//cout << buf << endl;
		Scanner scanner(buf);
		Parser parser(scanner,calc);
		parser.Parse();
		std::cout << parser.Calculate() << endl;
	}while(status!=STATUS_QUIT);
	return 0;
}