#include <iostream>
using namespace std;
#include "Parser.h"
#include "Scanner.h"
#include <string>
#include "Calc.h"
int main(void){
	Calc calc;
	STATUS status;
	do{
		cout << "> ";
		string buf;
		getline(cin,buf);
		//cout << buf << endl;
		Scanner scanner(buf);
		if(!scanner.IsEmpty()){
			Parser parser(scanner,calc);
			status=parser.Parse();
			if(status==STATUS_OK){
				std::cout << parser.Calculate() << endl;
			}
			else
				std::cout << "Syntax Error." << endl;
		}
		else
			std::cout << "Expression is empty." << std::endl;
	}while(status!=STATUS_QUIT);
	return 0;
}