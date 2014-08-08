#include <iostream>
using namespace std;
#include "Parser.h"
#include "Scanner.h"
#include <string>
#include "Exception.h"
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
		if(!scanner.IsEmpty()){
			Parser parser(scanner,calc);
			try{
				status=parser.Parse();
				if(status==STATUS_OK){
					std::cout << parser.Calculate() << endl;
				}
				
			}
			catch(SyntaxError& se){
				std::cout << se.what() << std::endl;
				std::cout << se.StackTrace() << std::endl;
			}
			catch(Exception& e){
				std::cout << e.what() << std::endl;
			}
			catch(...){
				std::cout << "Internal error." << std::endl;
			}
			
			
		}
		else
			std::cout << "Expression is empty." << std::endl;
	}while(status!=STATUS_QUIT);
	return 0;
}